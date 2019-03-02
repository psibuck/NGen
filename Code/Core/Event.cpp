//
//  Event.cpp
//  Emily
//
//  Created by Archie Buck on 17/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Core/Event.h"

namespace EMILY
{
    //--
    // Constructor
    //--
    Event::Event( void )
    : IdentifiableObject( 'EvnT' )
    {
    }
    
    //--
    // Equality operator overload
    //--
    bool Event::operator==( const Event rhs ) const
    {
        return ( this->get_id() == rhs.get_id() );
    }
}
