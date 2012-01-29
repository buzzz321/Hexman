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
    FileBuffer fb(80);

    fb.init("data.dat");

    std::vector<unsigned char> apa = fb.getLine();

    char expected = 0x12;

    EXPECT_EQ(static_cast<unsigned char>(expected), apa[0]);
}
