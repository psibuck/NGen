//
//  IdentifiableObject.h
//  Emily
//
//  Created by Archie Buck on 18/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef IdentifiableObject_h
#define IdentifiableObject_h

#include "Code/Types/Identifier.h"
#include <stdio.h>

namespace EMILY
{
    class IdentifiableObject
    {
    public:
        IdentifiableObject( const Identifier id_in );
        
        Identifier get_id( void ) const;
        
    private:
        Identifier id{ NULL_ID };
    };
}

#endif /* IdentifiableObject_h */
