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
    ball = std::make_unique<sf::CircleShape>( m_diameter );
    ball->setPosition( m_position.get_x(), m_position.get_y() );
    ball->setFillColor( sf::Color( 0, 0, 0 ) );
    ball->setOutlineThickness( 2.0f );
    ball->setOutlineColor( sf::Color( 255, 255, 255 ) );
}

//--
// Update function
//--
void Ball::update( void )
{
    ball->setPosition( ball->getPosition().x + m_x_speed, ball->getPosition().y + m_y_speed );
}

//--
// Method to draw the ball to the window
//--
void Ball::draw( sf::RenderWindow* window ) const
{
    window->draw( *ball );
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
EMILY::Point Ball::get_position( void )
{
    const EMILY::Point pos_vec = EMILY::Point( ball->getPosition().x, ball->getPosition().y );
    return pos_vec;
}

//--
// Speeds up the ball
//--
void Ball::speed_up( void )
{
    if( m_x_speed > 0 )
    {
        m_x_speed += 0.1f;
    }
    else
    {
        m_x_speed -= 0.1f;
    }
}
