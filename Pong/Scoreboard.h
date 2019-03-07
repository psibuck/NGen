//
//  Scoreboard.h
//  Emily
//
//  Created by Archie Buck on 05/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Scoreboard_hpp
#define Scoreboard_hpp

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

enum class PLAYER : short int
{
    ONE,
    TWO
};

namespace EMILY
{
    class Point;
}

class Scoreboard
{
public:
    Scoreboard( const EMILY::Point position, const EMILY::Point dimensions, const float countdown );
    
    bool has_ticked( void );
    void draw( sf::RenderWindow* window ) const;
    void update( void );
    void score( const PLAYER player );
    
private:
    int m_player_one_score{ 0 };
    int m_player_two_score{ 0 };
    const int m_time_to_speed_up{ 10 };
    std::unique_ptr<sf::Clock> mp_timer{ nullptr };
    std::unique_ptr<sf::RectangleShape> mp_board{ nullptr };
    std::unique_ptr<sf::Text> mp_player_one_score_text{ nullptr };
    std::unique_ptr<sf::Text> mp_player_two_score_text{ nullptr };
    std::unique_ptr<sf::Text> mp_countdown_text{ nullptr };
    std::unique_ptr<sf::Font> mp_scoreboard_font{ nullptr };
};

#endif /* Scoreboard_hpp */
