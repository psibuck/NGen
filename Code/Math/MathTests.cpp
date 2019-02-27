//
//  MathTests.cpp
//  Emily
//
//  When any new mathematical functionality is added tests should be added here that will fail
//  on project startup if any maths is broken
//
//  Created by Archie Buck on 21/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Math/MathTests.h"

#include "Code/Math/Vector3.h"
#include "Code/Core/Assert.h"

namespace EMILY
{
    //--
    // The public call that triggers the tests to run
    //--
    void MathTests::run( void )
    {
        test_vector_operations();
    }
    
    //--
    // Tests for the vector class "Code/Math/Vector3.h"
    //--
    void MathTests::test_vector_operations( void )
    {
        const int x = 1;
        const int y = 2;
        const int z = 3;
        const Vector3 vector1 = Vector3( x, y, z );
        
        //! Addition
        const Vector3 addition = vector1 + vector1;

        if(   addition.x != 2*x
           || addition.y != 2*y
           || addition.z != 2*z )
        {
            ASSERT_FAILED( "Vector addition test has failed" );
        }
        
        //! Subtraction
        const Vector3 subtraction = addition - vector1;
        if(   subtraction.x != x
           || subtraction.y != y
           || subtraction.z != z )
        {
            ASSERT_FAILED( "Vector subtraction test has failed" );
        }
        
        //! Equality
        ASSERT( "Vector equality test has failed", subtraction == vector1 );
        
        //! Inequality
        ASSERT( "Vector inequality test has failed", subtraction != addition );
        
        //! Scalar
        const Vector3 scaled_vector = vector1 * 2;
        if(   scaled_vector.x != 2*x
           || scaled_vector.y != 2*y
           || scaled_vector.z != 2*z )
        {
            ASSERT_FAILED( "Vector scaling test has failed" );
        }
    }
}

