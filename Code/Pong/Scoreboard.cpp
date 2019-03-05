//
//  Scoreboard.cpp
//  Emily
//
//  Created by Archie Buck on 05/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Pong/Scoreboard.h"

#include "Code/Math/Point.h"
#include "Code/Core/Assert.h"

//--
// Constructor
//--
Scoreboard::Scoreboard( const EMILY::Point position, const EMILY::Point dimensions, const float countdown )
{
    board = std::make_unique<sf::RectangleShape>();
    board->setPosition( position.get_x(), position.get_y() );
    board->setSize( sf::Vector2f( dimensions.get_x(), dimensions.get_y() ));
    board->setFillColor( sf::Color( 100, 100, 100 ));
    
    timer = std::make_unique<sf::Clock>();
    
    //sf::Font font;
    //if( !font.loadFromFile( "CaviarDreams.ttf"))
    //{
    //    ASSERT_FAILED( "Failed to load font" );
    //}
    //
    //if( !font.loadFromFile( "Platforms/Mac/Resources/Font/Caviar-Dreams/CaviarDreams.ttf"))
    //{
    //    ASSERT_FAILED( "Failed to load font" );
    //}
    
    const float y_text_coord = dimensions.get_y() + 100;
    player_one_score_text = std::make_unique<sf::Text>();
    player_one_score_text->setPosition( position.get_x() + dimensions.get_x()/4, y_text_coord );
    //player_one_score_text->setFont( font );
    player_one_score_text->setString( sf::String( "Test" ));
    player_one_score_text->setFillColor( sf::Color( 255, 255, 255 ));
    
    player_two_score_text = std::make_unique<sf::Text>();
    player_two_score_text->setPosition( position.get_x() + 3*(dimensions.get_x()/4), y_text_coord );
    
    countdown_text = std::make_unique<sf::Text>();
    countdown_text->setPosition( position.get_x() + dimensions.get_x()/2, y_text_coord );
}

//--
// Returns true if the timer has ticked to 0 and we should speed up the balll
//--
bool Scoreboard::has_ticked( void )
{
    if( timer->getElapsedTime().asSeconds() > 10.0f )
    {
        timer->restart();
        return true;
    }
    return false;
}

//--
// Draws the scoreboard to the screen
//--
void Scoreboard::draw(sf::RenderWindow *window) const
{
    window->draw( *board );
    window->draw( *player_one_score_text );
    window->draw( *player_two_score_text );
    window->draw( *countdown_text );
}

//--
// Updates the timer and the scores
//--
void Scoreboard::update( void )
{
    countdown_text->setString( sf::String( char( timer->getElapsedTime().asSeconds() )));
}
