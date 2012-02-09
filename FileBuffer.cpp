#include "FileBuffer.h"
#include <fstream>
#include <unistd.h>


using namespace std;
using namespace Program;



std::vector<unsigned char>
FileBuffer::getLine(){
    vector<unsigned char> retVal(this->rowLength);

    infile->read(reinterpret_cast<char*>(&retVal[0]), this->rowLength);
    this->bytesRead = infile->gcount();
    
    return retVal;
}

std::vector<std::vector<unsigned char> >
FileBuffer::getLines(std::size_t lines) {
    vector<vector<unsigned char> > retVal;
    std::size_t index = 0;

    while((index < lines) && !infile->fail()){
        ++index;
        vector<unsigned char> temp=getLine();
        retVal.push_back(temp);
    }
    return retVal;
}

bool FileBuffer::init(string filename){
//    char buffer[1024];
//    getcwd(buffer, sizeof(buffer)/sizeof(char));
//    cout<<buffer<<endl;

    this->filename = filename;
    this->infile = new fstream(this->filename.c_str() , ios::in | ios::binary);

    return this->infile->fail();
}


FileBuffer::~FileBuffer() {
    if ( infile != NULL ) {
        infile->close();

        delete this->infile;
    }
}
