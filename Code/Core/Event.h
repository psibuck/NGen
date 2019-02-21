//
//  Event.h
//  Emily
//
//  Created by Archie Buck on 17/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include "Code/Types/IdentifiableObject.h"

namespace EMILY
{
    class Event : public IdentifiableObject
    {
    public:
        Event( void );
        
        bool test( void ) { return false; }
        
    };
}


#endif /* Event_hpp */
