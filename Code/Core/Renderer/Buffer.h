//
//  Buffer.h
//  Emily
//
//  Created by Archie Buck on 26/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Buffer_h
#define Buffer_h

namespace EMILY
{
    class Buffer
    {
    public:
        Buffer( const void* data, const unsigned int size );
        ~Buffer( void );
        
        void bind( void ) const;
        void unbind( void ) const;
        
        int get_count( void ) const;
        
    private:
        unsigned int id;
        int m_count;
    };
}
#endif /* Buffer_h */
