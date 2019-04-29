//
//  Tennis.h
//  Emily
//
//  Created by Archie Buck on 14/04/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Tennis_hpp
#define Tennis_hpp

#include "Code/Core/Application.h"
#include "Tennis/Court.h"
#include "Tennis/TennisBall.h"
#include <array>

class Tennis : public EMILY::Application
{
    typedef EMILY::Application super;
    
public:
    Tennis();
    void initialise();
    void display();
    void update();
    
private:
    std::unique_ptr<Court> m_court;
    
    std::array<std::unique_ptr<TennisBall>, 100> m_balls;
};

#endif /* Tennis_hpp */
