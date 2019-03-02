//
//  Paddle.cpp
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Paddle.h"

#include "Code/Core/Event.h"

//--
// Constructor
//--
Paddle::Paddle( void ) : EMILY::Entity( 'padl' )
{
    register_event( EMILY::Event() );
}
