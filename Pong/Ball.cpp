//
//  Ball.cpp
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Pong/Ball.h"

#include "Code/Math/Point.h"
#include "Resources/Colours.h"


//--
// Constructor
//--
Ball::Ball( void ) : EMILY::Entity( 'ball' )
{
    m_ball = std::make_unique<sf::CircleShape>( m_diameter );
    m_ball->setPosition( m_position.get_x(), m_position.get_y() );
    m_ball->setFillColor( EMILY::COLOURS::BLACK );
    m_ball->setOutlineThickness( 2.0f );
    m_ball->setOutlineColor( EMILY::COLOURS::WHITE );
}

//--
// Update function
//--
void Ball::update( void )
{
    m_ball->setPosition( m_ball->getPosition().x + m_speed.get_x(), m_ball->getPosition().y + m_speed.get_y() );
}

//--
// Method to draw the ball to the window
//--
void Ball::draw( sf::RenderWindow* window ) const
{
    window->draw( *m_ball );
}

//--
// Changes the direction of the ball on contact
//--
void Ball::bounce( const AXIS axis )
{
    if( axis == AXIS::X )
    {
        m_speed.set_x( m_speed.get_x() * -1 );
    }
    else
    {
       m_speed.set_y( m_speed.get_y() * -1 );
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
    const EMILY::Point pos_vec = EMILY::Point( m_ball->getPosition().x, m_ball->getPosition().y );
    return pos_vec;
}

//--
// Speeds up the ball
//--
void Ball::speed_up( void )
{
    if( m_speed.get_x() > 0 )
    {
        m_speed.set_x( m_speed.get_x() + 0.1f );
    }
    else
    {
        m_speed.set_x( m_speed.get_x() - 0.1f );
    }
}

//--
// Called when we want the ball to return to the middle and at the default speed - e.g after a point scored
//--
void Ball::reset()
{
    m_ball->setPosition( 100.0f, 100.0f );
    m_speed = EMILY::Point( 15.0f, 15.0f );
}
