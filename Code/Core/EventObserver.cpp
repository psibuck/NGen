//
//  EventObserver.cpp
//  Emily
//
//  Created by Archie Buck on 19/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "EventObserver.h"

#include "Code/Core/Event.h"
#include "Code/Types/Identifier.h"

namespace EMILY
{
    //--
    // The base event handler message.Can be overriden by child classes
    //--
    bool EventObserver::handle_event( const Identifier event_id, Event& event )
    {
        //! to-do: Assert if we reach the end of this as we have sent an event to an observer that hasn't handled the event. This is unexpected behaviour
        return false;
    }
    
    //--
    // Checks this event against the events this observer is interested in to decide whether or not to send the event to it
    //--
    bool EventObserver::is_interested( Event* event )
    {
        for( auto ite : registered_events )
        {
            if( ite == event )
            {
                return true;
            }
        }
        return false;
    }
    
    //--
    // Registers an event that this class is interested in
    //--
    void EventObserver::register_event( Event* event )
    {
        registered_events.push_back( event );
    }
}

