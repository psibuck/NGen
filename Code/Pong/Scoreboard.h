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
    
private:
    int player_one_score{ 0 };
    int player_two_score{ 0 };
    int countdown{ 0 };
    std::unique_ptr<sf::Clock> timer{ nullptr };
    std::unique_ptr<sf::RectangleShape> board{ nullptr };
    std::unique_ptr<sf::Text>player_one_score_text{ nullptr };
    std::unique_ptr<sf::Text>player_two_score_text{ nullptr };
    std::unique_ptr<sf::Text>countdown_text{ nullptr };
};

#endif /* Scoreboard_hpp */
