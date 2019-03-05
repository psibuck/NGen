//
//  Application.h
//  Emily
//
//  Created by Archie Buck on 11/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include <memory>
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>

// Forward Declares
namespace EMILY
{
    class Event;
    class Window;
}

namespace EMILY
{
    class Application
    {
    public:
        Application();
        Application( const std::string& _name, const int _height, const int _width  );
        
        virtual void initialise( void );
        bool run( void );
        virtual void update( void ) {};
        virtual void process_events( void );
        virtual void clear( void );
        virtual void display( void );
        void shutdown( void );
        
    protected:
        virtual void handle_event( const sf::Event event );
        sf::RenderWindow* get_game_window( void );
        
    private:
        std::unique_ptr<sf::RenderWindow> m_game_window{ nullptr };
        bool m_is_running{ false };
        
        //! default name height and width
        std::string m_app_name{ "My Emily Application" };
        int m_height{ 800 };
        int m_width{ 600 };
    };
}


#endif /* Application_h */
