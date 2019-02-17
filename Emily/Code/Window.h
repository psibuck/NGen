//
//  Window.h
//  Emily
//
//  The base WINDOW Class that adds functionality on top of the base SFML windows class and holds
//  a pointer to the based window. Provides a cleaner interface between the application and SFML
//
//  Created by Archie Buck on 11/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Window_h
#define Window_h

#include <memory>

#include <SFML/Graphics.hpp>

namespace sf
{
    class RenderWindow;
}


namespace EMILY
{
    class Window
    {
    public:
        Window( const unsigned int height, const unsigned int width );
        
        void clear( void );
        void display( void );
        
    private:
        std::unique_ptr<sf::RenderWindow> m_application_window{ nullptr };
    };
}

#endif /* Window_h */
