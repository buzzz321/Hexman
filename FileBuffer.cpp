#include "FileBuffer.h"

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

FileBuffer::~FileBuffer() {
}
