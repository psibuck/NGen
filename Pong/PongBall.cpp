//
//  Ball.cpp
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Pong/PongBall.h"

#include "Code/Math/Point.h"
#include "Resources/Colours.h"


//--
// Constructor
//--
PongBall::PongBall( const EMILY::Point start_position )
: EMILY::Entity( 'ball' ), m_start_position( start_position )
{
    m_ball = std::make_unique<sf::CircleShape>( m_diameter );
    m_ball->setPosition( m_start_position.get_x(), m_start_position.get_y() );
    m_ball->setFillColor( EMILY::COLOURS::BLACK );
    m_ball->setOutlineThickness( 2.0f );
    m_ball->setOutlineColor( EMILY::COLOURS::WHITE );
}

//--
// Update function
//--
void PongBall::update( void )
{
    m_ball->setPosition( m_ball->getPosition().x + m_speed.get_x(), m_ball->getPosition().y + m_speed.get_y() );
}

//--
// Method to draw the ball to the window
//--
void PongBall::draw( sf::RenderWindow* window ) const
{
    window->draw( *m_ball );
}

//--
// Changes the direction of the ball on contact
//--
void PongBall::bounce( const AXIS axis )
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
float PongBall::get_radius( void ) const
{
    return m_diameter/2;
}

//--
// Provides a public interface to get the ball position
//--
EMILY::Point PongBall::get_position( void )
{
    const EMILY::Point pos_vec = EMILY::Point( m_ball->getPosition().x, m_ball->getPosition().y );
    return pos_vec;
}

//--
// Speeds up the ball
//--
void PongBall::speed_up( void )
{
    if( m_speed.get_x() > 0 )
    {
        m_speed.set_x( m_speed.get_x() + 1.0f );
    }
    else
    {
        m_speed.set_x( m_speed.get_x() - 1.0f );
    }
    sf::Color current_colour = m_ball->getOutlineColor();
    m_ball->setOutlineColor( sf::Color( 255, current_colour.g -= 25, current_colour.b -= 25 ));
}

//--
// Called when we want the ball to return to the middle and at the default speed - e.g after a point scored
//--
void PongBall::reset()
{
    m_ball->setPosition( m_start_position.get_x(), m_start_position.get_y() );
    m_speed = EMILY::Point( m_start_speed, m_start_speed );
    m_ball->setOutlineColor( EMILY::COLOURS::WHITE );
}
