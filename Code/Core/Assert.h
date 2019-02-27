//
//  Assert.h
//  Emily
//
//  Created by Archie Buck on 27/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Assert_hpp
#define Assert_hpp

#include <assert.h>

#define ASSERT( text, condition ) assert( text && condition )
#define ASSERT_FAILED( text ) ASSERT( text, 0 )

#endif /* Assert_hpp */
