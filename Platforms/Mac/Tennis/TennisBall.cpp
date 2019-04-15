//
//  TennisBall.cpp
//  Emily
//
//  Created by Archie Buck on 14/04/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Tennis/TennisBall.h"

#include "Resources/Colours.h"

//--
// Constructor
//--
TennisBall::TennisBall()
{
    setPosition( 200, 450 );
    setOutlineColor( EMILY::COLOURS::WHITE );
    setFillColor( EMILY::COLOURS::LIME_GREEN );
    setRadius( 6.0f );
}

//--
// Method to draw the ball to the window
//--
void TennisBall::draw( sf::RenderWindow* window ) const
{
    window->draw( *this );
}
