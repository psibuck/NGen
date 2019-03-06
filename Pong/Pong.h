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
#include "Pong/Ball.h"
#include "Pong/Paddle.h"
#include "Pong/Scoreboard.h"
#include <SFML/Graphics.hpp>

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
    typedef EMILY::Application super;
public:
    Pong( void );
    void initialise( void ) override;
    void display( void ) override;
    void update( void ) override;
    
    virtual void handle_event( sf::Event event ) final;
    
private:
    void check_for_collision( void );
    void handle_keypress( const sf::Keyboard::Key key  );
    void handle_key_release( const sf::Keyboard::Key key );
    
    GAME_STATE current_state{ GAME_STATE::MAIN_MENU };
    bool one_player{ true };
    std::unique_ptr<Ball> m_ball{ nullptr };
    std::unique_ptr<Paddle> m_paddle_one{ nullptr };
    std::unique_ptr<Paddle> m_paddle_two{ nullptr };
    std::unique_ptr<Scoreboard> m_scoreboard{ nullptr };
    
};
#include <stdio.h>

#endif /* Pong_h */
