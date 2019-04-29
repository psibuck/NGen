//
//  Ball.h
//  Emily
//
//  Created by Archie Buck on 14/04/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef TennisBall_hpp
#define TennisBall_hpp

#include "Code/Math/Vector3.h"

#include <SFML/Graphics.hpp>

class TennisBall : public sf::CircleShape
{
public:
    TennisBall( EMILY::Vector3 init_position, EMILY::Vector3 init_speed );
    
    void draw( sf::RenderWindow* window ) const;
    void update();
    
private:
    void set3DPosition( EMILY::Vector3 new_position );
    EMILY::Vector3 get3DPosition() const;
    
    void setSpeed( EMILY::Vector3 new_speed );
    const EMILY::Vector3& getSpeed() const;
    
    void bounce();
    void accelerate();
    
    EMILY::Vector3 m_speed;
    float m_height{ 0 };
};
#endif /* Ball_hpp */
