//
//  Ball.h
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include "Code/Types/Entity.h"
#include <SFML/Graphics.hpp>

namespace EMILY
{
    class Point;
}

enum class AXIS : short int
{
    X,
    Y
};

class Ball : public EMILY::Entity
{
public:
    Ball( void );
    
    void draw( sf::RenderWindow* window ) const;
    void update( void );
    void bounce( const AXIS axis );
    
    float get_radius( void ) const;
    EMILY::Point& get_position( void );
    
private:
    EMILY::Point m_position{ 0.0f, 0.0f };
    float m_x_speed{ 2.0f };
    float m_y_speed{ 2.0f };
    const float m_diameter{ 10.0f };
};

#endif /* Ball_hpp */
