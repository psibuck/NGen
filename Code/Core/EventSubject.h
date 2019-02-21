//
//  EventSubject.h
//  Emily
//
//  Created by Archie Buck on 19/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef EventSubject_hpp
#define EventSubject_hpp

#include <vector>

namespace EMILY
{
    class EventObserver;
}

namespace EMILY
{
#ifdef DEBUG
    constexpr int MAX_OBSERVERS{ 100 };
#endif // DEBUG
    
    class EventSubject
    {
    public:
        void add_observer( EventObserver* observer );
        void remove_observer( EventObserver* observer );
        
    private:
        std::vector<EventObserver*> observers{};
    };
}

#endif /* EventSubject_hpp */
