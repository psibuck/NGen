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
    void speed_up( void );
    void reset( void );
    float get_radius( void ) const;
    EMILY::Point get_position( void );
    
private:
    
    std::unique_ptr<sf::CircleShape> m_ball{ nullptr };
    EMILY::Point m_position{ 100.0f, 100.0f };
    EMILY::Point m_speed{ 12.0f, 12.0f };
    const float m_diameter{ 10.0f };
};

#endif /* Ball_hpp */
