//
//  Pong.cpp
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Pong/Pong.h"

#include "Code/Core/Renderer/Renderer.h"

constexpr float X_RESOLUTION = 1440;
constexpr float Y_RESOLUTION = 900;

//--
// Constructor
//--
Pong::Pong( void ) : EMILY::Application( "Pong", X_RESOLUTION, Y_RESOLUTION )
{
}

//--
// Initialise the game variables and state
//--
void Pong::initialise( void )
{
    current_state = GAME_STATE::IN_GAME;
    m_ball = std::make_unique<PongBall>( EMILY::Point( X_RESOLUTION/2, Y_RESOLUTION/2 ));
    m_paddle_one = std::make_unique<Paddle>( EMILY::Point( 40.0f, 850.0f ), EMILY::Point( 0.0f, Y_RESOLUTION ));
    m_paddle_two = std::make_unique<Paddle>( EMILY::Point( 1400.0f, 850.0f ), EMILY::Point( 0.0f, Y_RESOLUTION ));
    m_scoreboard = std::make_unique<Scoreboard>( EMILY::Point( 470, 200 ), EMILY::Point( 450, 250 ), 10.0f );
    super::initialise();
}

//--
// Draw the game objects
//--
void Pong::display( void )
{
    m_scoreboard->draw( get_game_window() );
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
    if( m_scoreboard->has_ticked() )
    {
        m_ball->speed_up();
        //m_scoreboard->reset_timer();
    }
    m_ball->update();
    m_paddle_one->update();
    m_paddle_two->update();
    m_scoreboard->update();
}

//--
// Checks the position of the ball against the window and the paddles
//--
void Pong::check_for_collision( void )
{
    auto collides = []( const float pos, const float l_bound, const float u_bound )
    {
        return (( pos > l_bound ) && ( pos < u_bound ));
    };
    
    const EMILY::Point ball_position = m_ball->get_position();
    const sf::Vector2<unsigned int> window_bounds = get_game_window()->getSize();
    const float x_position = ball_position.get_x();
    const float y_position = ball_position.get_y();
    const float ball_radius = m_ball->get_radius();
    
    if( !collides( x_position + ball_radius, 0, float( window_bounds.x )) )
    {
        m_ball->reset();
        if( x_position < 0 )
        {
            m_scoreboard->score( PLAYER::TWO );
        }
        else
        {
            m_scoreboard->score( PLAYER::ONE );
        }
    }
    
    if( !collides( y_position + ball_radius, 0, float( window_bounds.y )))
    {
        m_ball->bounce( AXIS::Y );
    }
    
    sf::RectangleShape* paddle_one = m_paddle_one->get_paddle();
    if( collides( y_position, paddle_one->getPosition().y, paddle_one->getPosition().y + paddle_one->getSize().y )
        && collides( x_position - ball_radius, paddle_one->getPosition().x, paddle_one->getPosition().x + paddle_one->getSize().x ))
    {
        m_ball->bounce( AXIS::X );
    }
    
    sf::RectangleShape* paddle_two = m_paddle_two->get_paddle();
    if( collides( y_position + ball_radius, paddle_two->getPosition().y, paddle_two->getPosition().y + paddle_two->getSize().y )
       && collides( x_position + ball_radius, paddle_two->getPosition().x, paddle_two->getPosition().x + paddle_two->getSize().x ))
    {
        m_ball->bounce( AXIS::X );
    }
    
}

//--
// Handles events
//--
void Pong::handle_event(sf::Event event)
{
    switch( event.type )
    {
        case sf::Event::KeyPressed:
            handle_keypress( event.key.code );
            break;
        case sf::Event::KeyReleased:
            handle_key_release( event.key.code );
            break;
        default:
            break;
    }
    
    super::handle_event( event );
}

//--
// Handles keypress
//--
void Pong::handle_keypress( const sf::Keyboard::Key key )
{
    switch( key )
    {
        case sf::Keyboard::Up:
        case sf::Keyboard::Down:
            m_paddle_two->handle_keypress( key );
            break;
        case sf::Keyboard::Q:
        case sf::Keyboard::A:
            m_paddle_one->handle_keypress( key );
            break;
        default:
            break;
    }
}

//--
// Handles key release
//--
void Pong::handle_key_release( const sf::Keyboard::Key key )
{
    switch( key )
    {
        case sf::Keyboard::Up:
        case sf::Keyboard::Down:
            m_paddle_two->handle_key_release( key );
            break;
        case sf::Keyboard::Q:
        case sf::Keyboard::A:
            m_paddle_one->handle_key_release( key );
            break;
        default:
            break;
    }
}

//--
// What should the game do when a point is scored
//--
void Pong::score( void )
{
    m_ball->reset();
}
