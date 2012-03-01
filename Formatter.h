//
//  Formatter.h
//  Hexman
//
//  Created by Anders Olme on 2012-03-01.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Hexman_Formatter_h
#define Hexman_Formatter_h
#include <vector>
#include <iostream>
#include <string>
namespace Program {
    class Formatter {
        int lineWidth;
    public:
        Formatter(int lineWidth);
        
        std::string 
        format(const std::vector<unsigned char> &binaryLine);
    };
}
#endif
