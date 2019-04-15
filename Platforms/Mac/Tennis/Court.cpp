//
//  Court.cpp
//  Emily
//
//  Created by Archie Buck on 14/04/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Court.h"

#include "Resources/Colours.h"

//--
// Initialise function which sets up all our data.
//--
Court::Court( const float window_width, const float window_height )
{
    const float x_margin = 100;
    const float court_length = window_width - 2 * x_margin;
    const float scalar = court_length / standard_length;
    const float court_height = scalar * doubles_width;
    
    m_main_court = std::make_unique<sf::RectangleShape>();
    m_main_court->setPosition( x_margin, 200 );
    m_main_court->setSize( sf::Vector2f( court_length, court_height ));
    
    m_main_court->setFillColor( EMILY::COLOURS::BLACK );
    m_main_court->setOutlineThickness( 2.0f );
    m_main_court->setOutlineColor( EMILY::COLOURS::WHITE );
    
    //! Singles lines
    m_singles_rect = std::make_unique<sf::RectangleShape>();
    const int margin = (doubles_width - singles_width) / 2;
    const float y_pos = 200 + margin * scalar;
    m_singles_rect->setPosition( m_main_court->getPosition().x, y_pos );
    m_singles_rect->setSize( sf::Vector2f( court_length, singles_width * scalar ));
    m_singles_rect->setFillColor( EMILY::COLOURS::BLACK );
    m_singles_rect->setOutlineThickness( 2.0f );
    m_singles_rect->setOutlineColor( EMILY::COLOURS::WHITE );
    
    //! Net
    m_net = std::make_unique<sf::RectangleShape>();
    m_net->setSize( sf::Vector2f( 25, court_height + 100 ));
    const float net_x = m_main_court->getPosition().x + m_main_court->getSize().x / 2 - m_net->getSize().x / 2;
    const float net_y = 200 - 50;
    m_net->setPosition( net_x, net_y );
    
    //! Servjce line rect
    m_service_line = std::make_unique<sf::RectangleShape>();
    const float length = service_line_from_net * scalar;
    m_service_line->setSize( sf::Vector2f( 2 * length, m_singles_rect->getSize().y ));
    m_service_line->setPosition( m_main_court->getPosition().x + m_main_court->getSize().x / 2 - length, m_singles_rect->getPosition().y );
    m_service_line->setFillColor( EMILY::COLOURS::BLACK );
    m_service_line->setOutlineThickness( 2.0f );
    m_service_line->setOutlineColor( EMILY::COLOURS::WHITE );
    
    //! middle line
    m_middle_line = std::make_unique<sf::RectangleShape>();
    m_middle_line->setSize( sf::Vector2f( m_service_line->getSize().x, 2 ));
    m_middle_line->setPosition( sf::Vector2f( m_service_line->getPosition().x, m_service_line->getPosition().y + m_service_line->getSize().y / 2 ));
}

//--
// Method to draw the court to the window
//--
void Court::draw( sf::RenderWindow* window ) const
{
    window->draw( *m_main_court );
    window->draw( *m_singles_rect );
    window->draw( *m_service_line );
    window->draw( *m_middle_line );
    window->draw( *m_net );
}
