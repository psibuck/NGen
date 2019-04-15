//
//  Ball.h
//  Emily
//
//  Created by Archie Buck on 14/04/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef TennisBall_hpp
#define TennisBall_hpp

#include <SFML/Graphics.hpp>

class TennisBall : public sf::CircleShape
{
public:
    TennisBall();
    void draw( sf::RenderWindow* window ) const;

private:
    int height;
};
#endif /* Ball_hpp */
