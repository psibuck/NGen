//
//  Pong.cpp
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Pong/Pong.h"

#include "Code/Core/Renderer/Renderer.h"

//--
// Constructor
//--
Pong::Pong( void ) : EMILY::Application( "Pong", 1440, 900 )
{
}

//--
// Initialise the game variables and state
//--
void Pong::initialise( void )
{
    current_state = GAME_STATE::IN_GAME;
    m_ball = std::make_unique<Ball>();
    m_paddle_one = std::make_unique<Paddle>( 1400.0f, 50.0f );
    m_paddle_two = std::make_unique<Paddle>( 40.0f, 850.0f );
    super::initialise();
}

//--
// Draw the game objects
//--
void Pong::display( void )
{
    m_ball->draw( get_game_window() );
    m_paddle_one->draw( get_game_window() );
    m_paddle_two->draw( get_game_window() );
    
    super::display();
}

//--
// Update the game objects
//--
void Pong::update( void )
{
    check_for_collision();
    m_ball->update();
}

//--
// Checks the position of the ball against the window and the paddles
//--
void Pong::check_for_collision( void )
{
    auto collides = []( const float pos, const float l_bound, const float u_bound )
    {
        return !(( pos > l_bound ) && ( pos < u_bound ));
    };
    
    const EMILY::Point ball_position = m_ball->get_position();
    const sf::Vector2<unsigned int> window_bounds = get_game_window()->getSize();
    const float x_position = ball_position.get_x();
    const float y_position = ball_position.get_y();
    const float ball_radius = m_ball->get_radius();
    
    if( collides( x_position + ball_radius, 0, window_bounds.x ) )
    {
        m_ball->bounce( AXIS::X );
        //! SCORE
    }
    
    if( collides( y_position + ball_radius, 0, window_bounds.y ))
    {
        m_ball->bounce( AXIS::Y );
    }
}
