#ifndef FILEBUFFER_H
#define FILEBUFFER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>
#include <string>

namespace Program {
    class FileBuffer {
        public:
            FileBuffer(std::size_t len);
            virtual ~FileBuffer ();

            std::vector<unsigned char> getLine();

            void init(std::string filename);
            void setFileStream(std::fstream *inFile) {
                this->infile = inFile;
            }
        private:
            std::fstream *infile;
            std::size_t rowLength;
            std::string filename;
    };

}
#endif /* end of include guard: FILEBUFFER_H */
