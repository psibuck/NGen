//
//  Point.h
//  Emily
//
//  Created by Archie Buck on 28/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Point_h
#define Point_h

namespace EMILY
{
    class Point
    {
    public:
        Point( const float _x, const float _y );
        
        float get_x( void ) const;
        float get_y( void ) const;
        void set_x( const float _x );
        void set_y( const float _y );
        
    private:
        float x{ 0.0 };
        float y{ 0.0 };
    };
}


#endif /* Point_h */
