//
//  Pong.h
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Pong_h
#define Pong_h

#include "Code/Core/Application.h"

enum class GAME_STATE : short int
{
    MAIN_MENU,
    IN_GAME
};

enum class DIFFICULTY : short int
{
    EASY,
    MEDIUM,
    HARD
};

class Pong : public EMILY::Application
{
public:
    void initialise( void ) override;
    
private:
    GAME_STATE current_state{ GAME_STATE::MAIN_MENU };
    bool one_player{ true };
    
};
#include <stdio.h>

#endif /* Pong_h */
