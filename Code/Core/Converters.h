//
//  Converters.h
//  Emily
//
//  Created by Archie Buck on 07/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Converters_h
#define Converters_h

#include <sstream>
#include <string>

namespace EMILY
{
    //--
    // Takes an int and returns a string
    //--
    static inline std::string string_from_int( const int x)
    {
        std::stringstream type;
        type << x;
        return type.str();
    }
    
    //--
    // Takes a float and returns a string
    //--
    static inline std::string string_from_float( const float x)
    {
        std::stringstream type;
        type << x;
        return type.str();
    }
}

#endif /* Converters_h */
