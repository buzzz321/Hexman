#include "FileBuffer.h"
#include <fstream>

using namespace std;
using namespace Program;

FileBuffer::FileBuffer(std::size_t len): rowLength(len) {
    cout<<this->rowLength<<endl;
}

std::vector<unsigned char>
FileBuffer::getLine(){
    vector<unsigned char> retVal(this->rowLength);

    infile->read(reinterpret_cast<char*>(&retVal[0]), this->rowLength);
    retVal.push_back(12);
    return retVal;
}

void FileBuffer::init(string filename){
    this->filename = filename;
    this->infile = new fstream(this->filename.c_str() , ios::in | ios::binary);
}


FileBuffer::~FileBuffer() {
    if ( infile != NULL ) {
        infile->close();

        delete this->infile;
    }
}
