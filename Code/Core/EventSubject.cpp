//
//  EventSubject.cpp
//  Emily
//
//  Created by Archie Buck on 19/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "EventSubject.h"

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
            if( *ite == observer )
            {
                //! to-do: Assert Trying to add an observer to the list that has already been added 
            }
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
                    //! to-do: Assert that we have removed the observer and then found another instance of it
                    continue;
                }
#endif // DEBUG
                observers.erase( ite );
                removed = true;
                break;

            }
        }
        //! to-do: Assert if we don't remove
    }
}
