//
//  Buffer.h
//  Emily
//
//  Created by Archie Buck on 26/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp

namespace EMILY
{
    class Buffer
    {
    public:
        Buffer( const int* data, int count );
        ~Buffer( void );
        
        void bind( void ) const;
        void unbind( void ) const;
        
        int get_count( void ) const;
        
    private:
        int id;
        int m_count;
    };
}
#endif /* Buffer_hpp */
