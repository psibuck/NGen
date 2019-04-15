//
//  Tennis.cpp
//  Emily
//
//  Created by Archie Buck on 14/04/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Tennis/Tennis.h"

constexpr float X_RESOLUTION = 1440;
constexpr float Y_RESOLUTION = 900;

//--
// Constructor
//--
Tennis::Tennis() : EMILY::Application( "Tennis", X_RESOLUTION, Y_RESOLUTION )
{
}

//--
// Initialises the object
//--
void Tennis::initialise()
{
    m_court = std::make_unique<Court>( X_RESOLUTION, Y_RESOLUTION );
    m_ball = std::make_unique<TennisBall>();
    super::initialise();
}

//--
// Called every frame to draw the objects to the screen
//--
void Tennis::display()
{
    m_court->draw( get_game_window() );
    m_ball->draw( get_game_window() );
    super::display();
}

//--
// Called every loop to update game states
//--
void Tennis::update()
{
}
