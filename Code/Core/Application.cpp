//
//  Application.cpp
//  Emily
//
//  Created by Archie Buck on 11/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Core/Application.h"

#include "Code/Core/Event.h"
#include "Code/Core/Renderer/Renderer.h"
#include "Code/Math/MathTests.h"
#include "SFML/Graphics.hpp"

namespace EMILY
{
    //--
    // Constructor
    //--
    Application::Application( const std::string& _name, const int _height, const int _width ) : m_app_name( _name ), m_height( _height ), m_width( _width )
    {
    }
    
    //--
    // The initialise method of the application. It sets up the application based on settings from an xml file
    //--
    void Application::initialise()
    {
#ifdef DEBUG
        MathTests::run();
#endif // DEBUG
        
        m_game_window = std::make_unique<Window>( m_app_name, m_height, m_width );
        Renderer::initialise();
        m_is_running = true;
    }
    
    //--
    // Clears the display at the end of every frame
    //--
    void Application::clear( void )
    {
        m_game_window->clear();
    }
    
    //--
    // The display method of the application which handles draws everything to the screen
    //--
    void Application::display( void )
    {
        m_game_window->display();
    }
    
    //--
    // The public event process call. Processes events from the different parts of the application
    //--
    void Application::process_events( void )
    {
        // First process the SFML events
        m_game_window->process_events();
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
        Renderer::get_instance().shutdown();
        m_game_window->close();
    }
}

