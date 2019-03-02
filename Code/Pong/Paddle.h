//
//  Paddle.h
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Paddle_h
#define Paddle_h

#include "Code/Core/EventObserver.h"
#include "Code/Types/Entity.h"


class Paddle : public EMILY::EventObserver, public EMILY::Entity
{
public:
    Paddle( void );
    
};

#endif /* Paddle_hpp */
