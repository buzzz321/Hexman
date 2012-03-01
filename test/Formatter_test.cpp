//
//  Formatter_test.cpp
//  Hexman
//
//  Created by Anders Olme on 2012-03-01.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "gtest/gtest.h"
#include "../Formatter.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
using namespace Program;

TEST(Formatter, Formatter) {
  Formatter formatter(8);
  vector<unsigned char> indata;
  indata.push_back(11);
  indata.push_back(22);
  indata.push_back(33);
  indata.push_back(44);
  indata.push_back(55);

  string ans = formatter.format(indata);

  EXPECT_EQ(string("11 22 33 44 55"), ans);

}
