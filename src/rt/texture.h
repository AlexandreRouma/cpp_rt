#pragma once
#include <rt/buffer.h>
#include <rt/types.h>
#include <memory>

namespace rt {
    class TextureClass {
    public:
        TextureClass() {}
        virtual ~TextureClass() {}
        virtual glm::vec3 map(vec2l texCoord) = 0;
    };

    class Texture : public std::shared_ptr<TextureClass> {
    public:
        Texture() : std::shared_ptr<TextureClass>() {}
        Texture(std::shared_ptr<TextureClass> texture) : std::shared_ptr<TextureClass>(texture) {}
    };
}