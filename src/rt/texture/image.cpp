#include <rt/texture/image.h>

namespace rt::texture {
    ImageClass::ImageClass(Buffer<glm::vec3> pixels, vec2l u, vec2l v) {
        _pixels = pixels;
        _u = u;
        _v = v;
        pixWidth = _pixels->getWidth();
        pixHeight = _pixels->getHeight();
    }

    glm::vec3 ImageClass::map(vec2l texCoord) {
        // TODO: IMPLEMENT
        return glm::vec3();
    }

    void ImageClass::setPixels(Buffer<glm::vec3> pixels) {
        _pixels = pixels;
        pixWidth = _pixels->getWidth();
        pixHeight = _pixels->getHeight();
    }

    void ImageClass::setMapping(vec2l u, vec2l v) {
        _u = u;
        _v = v;
    }

    Texture Image(Buffer<glm::vec3> pixels, vec2l u, vec2l v) {
        return Texture(std::dynamic_pointer_cast<TextureClass>(std::make_shared<ImageClass>(pixels, u, v)));
    }
}