//
//  Renderer.h
//  Emily
//
//  Created by Archie Buck on 26/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

namespace EMILY
{
    class Buffer;
    class Shader;
    class VertexArray;
}

namespace EMILY
{
    struct RenderData
    {
        Buffer& buffer;
        Shader& shader;
        VertexArray& vertex_array;
    };
    
    class Renderer
    {
    public:
        void draw( const RenderData& data );
    private:
        
    };
}
#endif /* Renderer_hpp */
