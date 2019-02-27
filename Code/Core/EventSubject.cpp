//
//  EventSubject.cpp
//  Emily
//
//  Created by Archie Buck on 19/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Core/EventSubject.h"

#include "Code/Core/Assert.h"

namespace EMILY
{
    //--
    // Adds an observer to the stored array of observers. In debug we search the list and make sure this isn't duplication
    //--
    void EventSubject::add_observer(EventObserver* observer)
    {
#ifdef DEBUG
        for( auto ite = observers.begin(); ite != observers.end(); ite++ )
        {
            ASSERT( "Trying to add an observer to the list that has already been added", *ite == observer );
        }
#endif // DEBUG
        
        observers.push_back( observer );
        
#ifdef DEBUG
        //! to-do: Assert if observers gets above 100. It's time to reconsider our design pattern
#endif // DEBUG
    }
    
    //--
    // Searches the list of observers and removes the instance. If we don't find it or we find multiple instances we assert
    //--
    void EventSubject::remove_observer(EventObserver* observer)
    {
        bool removed = false;
        for( auto ite = observers.begin(); ite != observers.end(); ite++ )
        {
            if( *ite == observer )
            {
#ifdef DEBUG
                if( removed )
                {
                    ASSERT_FAILED( "We have found another instance of the removed listener in our array. It should have never been added or we unsuccessfully removed the old one" );
                }
#endif // DEBUG
                observers.erase( ite );
                removed = true;
                break;

            }
        }
        ASSERT_FAILED( "We came here with the purpose of removing an observer. We have failed to find/remove it." );
    }
}
