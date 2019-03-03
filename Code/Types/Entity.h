//
//  Entity.h
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "Code/Math/Point.h"
#include "Code/Types/IdentifiableObject.h"
#include "SFML/Graphics.hpp"

namespace EMILY
{
    class Entity : public IdentifiableObject, public sf::Sprite
    {
    public:
        Entity( const Identifier id );
        
    private:

    };
}
#endif /* Entity_hpp */
