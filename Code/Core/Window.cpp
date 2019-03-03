//
//  Window.cpp
//  Emily
//
//  Created by Archie Buck on 11/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Core/Window.h"

namespace EMILY
{
    //--
    // Class Constructor
    //--
    Window::Window( const std::string& app_name, const unsigned int height, const unsigned int width )
    {
        // Create the main window
        m_application_window = std::make_unique<sf::RenderWindow>( sf::VideoMode(height, width), app_name );
    }
    
    //--
    // Clear function wipes the whole window.
    //--
    void Window::clear( void )
    {
        // Log
        m_application_window->clear();
    }
    
    
    //--
    // Display function tells the window to update the display to show our new screen
    //--
    void Window::display( void )
    {
        // Log
        m_application_window->display();
    }
    
    //--
    // Process the events sent to us from the application window
    //--
    void Window::process_events()
    {
        sf::Event event;
        while( m_application_window->pollEvent( event ))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                close();
            }
        }
    }
    
    //--
    // Close is called when the window is being destroyed.
    //--
    void Window::close()
    {
        //! to-do: Send event telling program to shutdown
        m_application_window->close();
    }
}

