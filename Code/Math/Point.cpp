//
//  Point.cpp
//  Emily
//
//  Created by Archie Buck on 28/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Math/Point.h"

namespace EMILY
{
    //--
    // Constructor
    //--
    Point::Point( const float _x, const float _y ) : x( _x ), y( _y )
    {
    }
    
    //--
    // Returns x value of point
    //--
    float Point::get_x( void ) const
    {
        return x;
    }
    
    //--
    // Returns y value of point
    //--
    float Point::get_y( void ) const
    {
        return y;
    }
    
    //--
    // Provides a public interface to set x
    //--
    void Point::set_x( const float _x )
    {
        x = _x;
    }
    
    //--
    // Provides a public interface to set y
    //--
    void Point::set_y( const float _y )
    {
        y = _y;
    }
}
