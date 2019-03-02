//
//  EventObserver.h
//  Emily
//
//  Created by Archie Buck on 19/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef EventObserver_hpp
#define EventObserver_hpp

#include "Code/Types/Identifier.h"
#include <vector>

namespace EMILY
{
    class Event;
}

namespace EMILY
{
    class EventObserver
    {
    public:
        virtual bool handle_event( const Identifier event_id, Event& event );
        
        bool is_interested( const Event event );
        
    protected:
        void register_event( const Event event );
        
    private:
        std::vector<Event> registered_events;
    };
}
#endif /* EventObserver_hpp */
