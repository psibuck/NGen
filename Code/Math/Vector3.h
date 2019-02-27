//
//  Vector3.h
//  Emily
//
//  Created by Archie Buck on 21/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Vector3_hpp
#define Vector3_hpp

#include <stdio.h>

namespace EMILY
{
    class Vector3
    {
    public:
        Vector3( const float x_in, const float y_in, const float z_in );
        
        
        //! note: We declare these as public to avoid get_x(). get_y(). etc. ref: https://www.haroldserrano.com/blog/tips-on-developing-a-math-library-for-your-game-engine
        float x;
        float y;
        float z;
    
        Vector3 operator+( const Vector3& rhs ) const;
        Vector3 operator-( const Vector3& rhs ) const;
        Vector3 operator*( const int scalar ) const;
        bool operator==( const Vector3& rhs ) const;
        bool operator!=( const Vector3& rhs ) const;
        
    private:

    };
}
#endif /* Vector3_hpp */
