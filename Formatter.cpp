//
//  Formatter.cpp
//  Hexman
//
//  Created by Anders Olme on 2012-03-01.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Formatter.h"

using namespace std;
using namespace Program;

typedef vector<unsigned char>::const_iterator binarylineiterator;

Formatter::Formatter(int lineWidth): lineWidth(lineWidth) {

}

std::string
Formatter::format(const std::vector<unsigned char> &binaryLine){
  
  ostringstream result;

  for (binarylineiterator it = binaryLine.begin(), itend =  binaryLine.end(); it != itend; ++it){
    result << (char)(*it) ;//fix some kind of bcd..
  }

  return result.str();
}
