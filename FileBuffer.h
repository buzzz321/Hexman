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
            std::vector<std::vector<unsigned char> > getLines(std::size_t lines);

            bool init(std::string filename);
            void setFileStream(std::fstream *inFile) {
                this->infile = inFile;
            }

            std::size_t getBytesRead() const {
                return this->bytesRead;
            }
        private:
            std::fstream *infile;
            std::size_t rowLength;
            std::size_t bytesRead;
            std::string filename;
    };

}
#endif /* end of include guard: FILEBUFFER_H */
