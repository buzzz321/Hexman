#include "gtest/gtest.h"
#include "../FileBuffer.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
using namespace Program;

/*
TEST(FileBuffer, getLine) {
    FileBuffer fb(80);
    std::stringstream mock;

    mock<<"asdfghjkl";

    fb.setFileStream(&mock);
    std::vector<unsigned char> apa = fb.getLine();

    char expected = 'd';

    EXPECT_EQ(static_cast<unsigned char>(expected), apa[2]);
}
*/
TEST(FileBuffer, getLineFileData) {
    FileBuffer fb(8);

    bool fail = fb.init("data.dat");
    EXPECT_EQ(false, fail);

    std::vector<unsigned char> apa = fb.getLine();
    std::cout<<fb.getBytesRead()<<std::endl;

    char expected = 0x12;
    EXPECT_EQ(static_cast<unsigned char>(expected), apa[0]);
}
TEST(FileBuffer, getLinesFileData) {
    FileBuffer fb(16);

    bool fail = fb.init("data.dat");
    EXPECT_EQ(false, fail);

    std::vector<std::vector<unsigned char> > apa = fb.getLines(3);
    std::cout<<fb.getBytesRead()<<std::endl;

    char expected = 0xAA;
    EXPECT_EQ(static_cast<unsigned char>(expected), apa[1][0]);
    
    expected = 0x55;
    EXPECT_EQ(static_cast<unsigned char>(expected), apa[2][0]);
}
