#pragma once
#include <rt/texture.h>

namespace rt::texture {
    class SolidClass : public TextureClass {
    public:
        SolidClass(glm::vec3 color);

        glm::vec3 map(vec2l texCoord);

        void setColor(glm::vec3 color);

    private:
        glm::vec3 _color;

    };

    Texture Solid(glm::vec3 color);
}