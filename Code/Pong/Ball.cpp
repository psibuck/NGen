//
//  Ball.cpp
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Pong/Ball.h"

#include "Code/Math/Point.h"


//--
// Constructor
//--
Ball::Ball( void ) : EMILY::Entity( 'ball' )
{
}

//--
// Update function
//--
void Ball::update( void )
{
    m_position.set_x( m_position.get_x() + m_x_speed );
    m_position.set_y( m_position.get_y() + m_y_speed );
}

//--
// Method to draw the ball to the window
//--
void Ball::draw( sf::RenderWindow* window ) const
{
    sf::CircleShape ball = sf::CircleShape( m_diameter );
    ball.setPosition( m_position.get_x(), m_position.get_y() );
    ball.setFillColor(sf::Color(0, 0, 0));
    ball.setOutlineThickness(2.0f);
    ball.setOutlineColor(sf::Color(255, 255, 255));
    window->draw( ball );
}

//--
// Changes the direction of the ball on contact
//--
void Ball::bounce( const AXIS axis )
{
    if( axis == AXIS::X )
    {
        m_x_speed *= -1;
    }
    else
    {
        m_y_speed *= -1;
    }
}

//--
// Returns the radius of the ball
//--
float Ball::get_radius( void ) const
{
    return m_diameter/2;
}

//--
// Provides a public interface to get the ball position
//--
EMILY::Point& Ball::get_position( void )
{
    return m_position;
}
