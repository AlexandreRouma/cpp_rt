#pragma once
#include <rt/texture.h>
#include <rt/buffer.h>

namespace rt::texture {
    class ImageClass : public TextureClass {
    public:
        ImageClass(Buffer<glm::vec3> pixels, vec2l u, vec2l v);

        glm::vec3 map(vec2l texCoord);

        void setPixels(Buffer<glm::vec3> pixels);
        void setMapping(vec2l u, vec2l v);

    private:
        Buffer<glm::vec3> _pixels;
        vec2l _u;
        vec2l _v;
        int pixWidth;
        int pixHeight;

    };

    Texture Image(Buffer<glm::vec3> pixels, vec2l u, vec2l v);
}