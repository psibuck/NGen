//
//  Buffer.cpp
//  Emily
//
//  Created by Archie Buck on 26/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Buffer.h"


namespace EMILY
{
    //--
    // Constructor
    //--
    Buffer::Buffer( const int* data, int count )
    {
    }
    
    //--
    // Destructor
    //--
    Buffer::~Buffer()
    {
    }
    
    //--
    // Returns the number of elements in the buffer
    //--
    int Buffer::get_count() const
    {
        return m_count;
    }
}
