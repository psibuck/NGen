//
//  Court.h
//  Emily
//
//  Created by Archie Buck on 14/04/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Court_hpp
#define Court_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <memory>

//! All in feet
constexpr int standard_length = 78;
constexpr int singles_width = 27;
constexpr int doubles_width = 36;
constexpr int service_line_from_net = 21;
constexpr int net_height = 3;
constexpr int new_width = 42;

class Court
{
public:
    Court( const float window_width, const float window_height );
    void initialise();
    void draw( sf::RenderWindow* window ) const;
    
private:
    std::unique_ptr<sf::RectangleShape> m_main_court;
    std::unique_ptr<sf::RectangleShape> m_net;
    std::unique_ptr<sf::RectangleShape> m_singles_rect;
    std::unique_ptr<sf::RectangleShape> m_service_line;
    std::unique_ptr<sf::RectangleShape> m_middle_line;
};

#endif /* Court_hpp */
