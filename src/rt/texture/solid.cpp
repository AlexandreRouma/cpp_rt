#include <rt/texture/solid.h>

namespace rt::texture {
    SolidClass::SolidClass(glm::vec3 color) {
        _color = color;
    }

    glm::vec3 SolidClass::map(vec2l texCoord) {
        return _color;
    }

    void SolidClass::setColor(glm::vec3 color) {
        _color = color;
    }

    Texture Solid(glm::vec3 color) {
        return Texture(std::dynamic_pointer_cast<TextureClass>(std::make_shared<SolidClass>(color)));
    }
}