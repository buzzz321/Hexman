#include "gtest/gtest.h"
#include "../FileBuffer.h"
#include <vector>

using namespace Program;

TEST(FileBuffer, getLine) {
    FileBuffer fb(80);
    std::vector<unsigned char> apa = fb.getLine();

    EXPECT_EQ(12, apa.back());
}
