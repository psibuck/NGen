//
//  IdentifiableObject.cpp
//  Emily
//
//  Created by Archie Buck on 18/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Types/IdentifiableObject.h"


namespace EMILY
{
    //--
    // Constructor
    //--
    IdentifiableObject::IdentifiableObject( const Identifier id_in )
    : id( id_in )
    {
    }
    
    //--
    // Returns the id of the object
    //--
    Identifier IdentifiableObject::get_id( void ) const
    {
        return id;
    }
}
