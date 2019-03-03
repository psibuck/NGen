//
//  Paddle.h
//  Emily
//
//  Created by Archie Buck on 02/03/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Paddle_h
#define Paddle_h

#include "Code/Types/Entity.h"


class Paddle : public EMILY::Entity
{
public:
    Paddle( const float x_in, const float y_in );
    
    void draw( sf::RenderWindow* window ) const;
    
private:
    float x{ 0.0f };
    float y{ 0.0f };
    const float height{ 85.0f };
    const float width{ 15.0f };
};

#endif /* Paddle_hpp */
