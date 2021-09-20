#include <rt/material/light_source.h>
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/vector_angle.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

namespace rt::material {
    LightSourceClass::LightSourceClass(Texture texture, float intensity) {
        _texture = texture;
        _intensity = intensity;
    }

    bool LightSourceClass::brdf(vec3l incident, vec3l normal, vec3l intersection, vec2l texCoord, glm::vec3 color, vec3l& outputDir, glm::vec3& outputColor) {
        outputColor = color * _texture->map(texCoord) * _intensity;
        return false;
    }

    void LightSourceClass::setTexture(Texture texture) {
        _texture = texture;
    }

    void LightSourceClass::setIntensity(float intensity) {
        _intensity = intensity;
    }
}