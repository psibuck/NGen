//
//  MathTests.h
//  Emily
//
//  Created by Archie Buck on 21/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef MathTests_hpp
#define MathTests_hpp

#include <stdio.h>

namespace EMILY
{
    class MathTests
    {
    public:
        static void run( void );
        
    private:
        //! Vectors
        static void test_vector_operations( void );
    };
}
#endif /* MathTests_hpp */
