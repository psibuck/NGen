//
//  Paddle.cpp
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Paddle.h"

#include <SFML/Graphics.hpp>

//--
// Constructor
//--
Paddle::Paddle( const float x_in, const float y_in ) : EMILY::Entity( 'padl' ), x( x_in ), y( y_in )
{
}

//--
// Draws the paddle to the screen
//--
void Paddle::draw(sf::RenderWindow *window) const
{
    sf::RectangleShape paddle = sf::RectangleShape( sf::Vector2f( width, height ));
    paddle.setPosition( x, y );
    paddle.setFillColor( sf::Color( 255, 255, 255 ));
    window->draw( paddle );
}
