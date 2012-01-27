#ifndef FILEBUFFER_H
#define FILEBUFFER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>
namespace Program {
    class FileBuffer {
        public:
            FileBuffer(std::size_t len);
            virtual ~FileBuffer ();

            std::vector<unsigned char> getLine();    


            void setFileStream(std::istream *inFile) {
                this->infile = inFile;
            }
        private:
            std::istream *infile;
            std::size_t rowLength;
    };

}
#endif /* end of include guard: FILEBUFFER_H */
