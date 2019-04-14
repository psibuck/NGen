//
//  Scoreboard.cpp
//  Emily
//
//  Created by Archie Buck on 05/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Pong/Scoreboard.h"

#include "Code/Math/Point.h"
#include "Code/Core/Assert.h"
#include "Code/Core/Converters.h"
#include "Resources/Colours.h"

//--
// Constructor
//--
Scoreboard::Scoreboard( const EMILY::Point position, const EMILY::Point dimensions, const float countdown )
{
    mp_board = std::make_unique<sf::RectangleShape>();
    mp_board->setPosition( position.get_x(), position.get_y() );
    mp_board->setSize( sf::Vector2f( dimensions.get_x(), dimensions.get_y() ));
    mp_board->setFillColor( EMILY::COLOURS::GREY );
    
    mp_timer = std::make_unique<sf::Clock>();
    
    mp_scoreboard_font = std::make_unique<sf::Font>();

#ifdef _WIN32
	if ( !mp_scoreboard_font->loadFromFile( "C:/Programming/Engines/Emily/emily-engine/Resources/Font/Caviar-Dreams/CaviarDreams.ttf" ) )
	{
		ASSERT_FAILED( "Failed to load font" );
	}
#else
	if ( !mp_scoreboard_font->loadFromFile( "/Users/Archie/Documents/Programming/C++/Engines/Emily/Resources/Font/Caviar-Dreams/CaviarDreams.ttf" ) )
	{
		ASSERT_FAILED( "Failed to load font" );
	}
#endif // _WIN32

    const int text_size = 75;
    const float y_text_coord = dimensions.get_y() + 25;
    mp_player_one_score_text = std::make_unique<sf::Text>();
    mp_player_one_score_text->setPosition( position.get_x() + dimensions.get_x()/4 - 45, y_text_coord );
    mp_player_one_score_text->setFont( *mp_scoreboard_font );
    mp_player_one_score_text->setString( sf::String( "0" ));
    mp_player_one_score_text->setCharacterSize( text_size );
    mp_player_one_score_text->setFillColor( EMILY::COLOURS::WHITE );
    
    mp_player_two_score_text = std::make_unique<sf::Text>();
    mp_player_two_score_text->setPosition( position.get_x() + 3*(dimensions.get_x()/4), y_text_coord );
    mp_player_two_score_text->setFont( *mp_scoreboard_font );
    mp_player_two_score_text->setString( sf::String( "0" ));
    mp_player_two_score_text->setCharacterSize( text_size );
    
    mp_countdown_text = std::make_unique<sf::Text>();
    mp_countdown_text->setPosition( position.get_x() + dimensions.get_x()/2 - 25, y_text_coord + 25 );
    mp_countdown_text->setFont( *mp_scoreboard_font );
}

//--
// Returns true if the timer has ticked to 0 and we should speed up the balll
//--
bool Scoreboard::has_ticked( void )
{
    if( mp_timer->getElapsedTime().asSeconds() > 10.0f )
    {
        mp_timer->restart();
        return true;
    }
    return false;
}

//--
// Draws the scoreboard to the screen
//--
void Scoreboard::draw(sf::RenderWindow *window) const
{
    window->draw( *mp_board );
    window->draw( *mp_player_one_score_text );
    window->draw( *mp_player_two_score_text );
    window->draw( *mp_countdown_text );
}

//--
// Updates the timer and the scores
//--
void Scoreboard::update( void )
{
    mp_countdown_text->setString( sf::String( EMILY::string_from_int( m_time_to_speed_up - (int)mp_timer->getElapsedTime().asSeconds() )));
}

//--
// Increments the score
//--
void Scoreboard::score(const PLAYER player)
{
    switch ( player )
    {
        case PLAYER::ONE:
            m_player_one_score++;
            mp_player_one_score_text->setString( sf::String( EMILY::string_from_int( m_player_one_score )));
            break;
        case PLAYER::TWO:
            m_player_two_score++;
            mp_player_two_score_text->setString( sf::String( EMILY::string_from_int( m_player_two_score )));
            break;
    };
    mp_timer->restart();
}

