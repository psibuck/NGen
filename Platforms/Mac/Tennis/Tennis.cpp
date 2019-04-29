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
    
    float init_x = 20;
    float init_y = 20;
    float init_h = 100;
    
    for( auto ite = 0; ite < 100; ite++ )
    {
        m_balls[ite] = std::make_unique<TennisBall>( EMILY::Vector3( init_x, init_y, init_h ), EMILY::Vector3( 0.0f, 0.0f, -0.2f ));
        init_x = std::rand() % 1440;
        init_y = std::rand() % 900;
        init_h = std::rand() % 400;
    }

    super::initialise();
}

//--
// Called every frame to draw the objects to the screen
//--
void Tennis::display()
{
    m_court->draw( get_game_window() );
    for( auto ite = 0; ite < 100; ite++ )
    {
        m_balls[ite]->draw( get_game_window() );
    }
    super::display();
}

//--
// Called every loop to update game states
//--
void Tennis::update()
{
    for( auto ite = 0; ite < 100; ite++ )
    {
        m_balls[ite]->update();
    }
}
