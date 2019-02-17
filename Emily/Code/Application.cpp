//
//  Application.cpp
//  Emily
//
//  Created by Archie Buck on 11/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Emily/Code/Application.h"

#include "Emily/Code/Event.h"
#include "SFML/Graphics.hpp"

namespace EMILY
{
    
    //--
    // The initialise method of the application. It sets up the application based on settings from an xml file
    //--
    void Application::initialise()
    {
        m_game_window = std::make_unique<Window>(800, 600);
        
        m_is_running = true;
    }
    
    //--
    // The display method of the application which handles draws everything to the screen
    //--
    void Application::display( void )
    {
        m_game_window->clear();
        
        m_game_window->display();
    }
    
    //--
    // The public event process call. Processes events from the different parts of the application
    //--
    void Application::process_events( void )
    {
        // First process the SFML events
        m_game_window->process_events();
        
        Event event;
        while ( process_application_events( event ) )
        {
        }
    }
    
    
    //--
    // Process application events which are going to be stored in an event queue
    //--
    bool Application::process_application_events( Event& event )
    {
        return event.test();
    }
    
    //--
    // The run method is the application controller. When it returns false we shutdown
    //--
    bool Application::run( void )
    {
        return m_is_running;
    }
    
    
    //--
    // *Insert function purpose here*
    //--
    void Application::shutdown( void )
    {
        m_game_window->close();
    }
}

