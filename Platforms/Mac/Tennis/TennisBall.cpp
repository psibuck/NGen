//
//  TennisBall.cpp
//  Emily
//
//  Created by Archie Buck on 14/04/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Tennis/TennisBall.h"

#include "Code/Math/Vector3.h"
#include "Resources/Colours.h"

#include <cstdlib>
#include <iostream>

constexpr float actual_diameter = 6.0f;
constexpr float max_height = 100.0f;
constexpr float terminal_velocity = 1.0f;


//--
// Constructor
//--
TennisBall::TennisBall( EMILY::Vector3 init_position, EMILY::Vector3 init_speed ) : m_speed( init_speed )
{
    setOutlineColor( EMILY::COLOURS::WHITE );
    setFillColor( EMILY::COLOURS::LIME_GREEN );
    setRadius( actual_diameter );
    
    set3DPosition( init_position );
}

//--
// Updates the tennis ball every frame
//--
void TennisBall::update()
{
    set3DPosition( get3DPosition() + getSpeed() );
    //! We are falling
    if( getSpeed().z < 0.0f )
    {
        std::cout << "We are falling" << std::endl;
        m_height = std::max( 0.0f, m_height + m_speed.z );
        if( m_height == 0.0f )
        {
            std::cout << "We hit the floor" << std::endl;
            bounce();
        }
        else
        {
            accelerate();
        }
    }
    else
    {
        m_height += m_speed.z;
        if( m_speed.z < 0.2f )
        {
            m_speed.z = -m_speed.z;
        }
        else
        {
            m_speed.z *= 0.95f;
        }
    }
    
    const float new_diameter = 1.05 * m_height + actual_diameter;
    setRadius( new_diameter );
}

//--
// Affects the ball on contact with the ground
//--
void TennisBall::bounce()
{
    std::cout << "BOUNCE" << std::endl;
    m_speed.z = -m_speed.z * 0.46f;
}

//--
// Handles acceleration of the ball
//--
void TennisBall::accelerate()
{
    std::cout << "Current speed: " << m_speed.z << std::endl;
    if( m_speed.z < terminal_velocity )
    {
        m_speed.z *= 1.06f;
    }
    std::cout << "New speed: " << m_speed.z << std::endl;
}

//--
// Method to draw the ball to the window
//--
void TennisBall::draw( sf::RenderWindow* window ) const
{
    window->draw( *this );
}

//--
// Returns the current position of the ball in 3-dimensions
EMILY::Vector3 TennisBall::get3DPosition() const
{
    const sf::Vector2f pos = getPosition();
    const EMILY::Vector3 current_pos = EMILY::Vector3( pos.x, pos.y, m_height );
    return current_pos;
}

//--
// Returns the current speed of the tennis ball as a 3-d vector
//--
const EMILY::Vector3& TennisBall::getSpeed() const
{
    return m_speed;
}

//--
//--
// Updates the position of the ball
//--
void TennisBall::set3DPosition( const EMILY::Vector3 new_position )
{
    setPosition( new_position.x, new_position.y );
    m_height = new_position.z;
}

//--
// Updates the speed of the ball
//--
void TennisBall::setSpeed( const EMILY::Vector3 new_speed )
{
    m_speed = new_speed;
}

