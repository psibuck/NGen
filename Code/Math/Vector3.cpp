//
//  Vector3.cpp
//  Emily
//
//  Created by Archie Buck on 21/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Vector3.h"

namespace EMILY
{
    //--
    // Constructor
    //--
    Vector3::Vector3( const float x_in, const float y_in, const float z_in )
    : x( x_in ), y( y_in ), z( z_in )
    {
    }
    
    //--
    // Addition operator overload
    //--
    Vector3 Vector3::operator+( const Vector3& rhs ) const
    {
        return Vector3( this->x + rhs.x, this->y + rhs.y, this->z + rhs.z );
    }
    
    //--
    // Subtraction operator overload
    //--
    Vector3 Vector3::operator-( const Vector3& rhs ) const
    {
        return Vector3( this->x - rhs.x, this->y - rhs.y, this->z - rhs.z );
    }
    
    //--
    // Equality operator overload
    //--
    bool Vector3::operator==( const Vector3& rhs ) const
    {
        return ( this->x == rhs.x && this->y == rhs.y && this->z == rhs.z );
    }
    
    //--
    // Inequality operator overload
    //--
    bool Vector3::operator!=( const Vector3& rhs ) const
    {
        return( this->x != rhs.x || this->y != rhs.y || this->z != rhs.z );
    }
}
