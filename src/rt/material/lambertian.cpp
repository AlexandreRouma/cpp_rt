#include <rt/material/lambertian.h>
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <memory>
#define _USE_MATH_DEFINES
#include <math.h>

namespace rt::material {
    LambertianClass::LambertianClass(Texture texture) {
        _texture = texture;
    }

    bool LambertianClass::brdf(vec3l incident, vec3l normal, vec3l intersection, vec2l texCoord, glm::vec3 color, vec3l& outputDir, glm::vec3& outputColor) {
        // Generate a relected ray
        outputDir = glm::sphericalRand(1.0);
        if (glm::angle(outputDir, normal) > M_PI) {
            outputDir = -outputDir;
        }

        // Calculate output color
        outputColor = color * _texture->map(texCoord);

        return true;
    }

    void setTexture(Texture texture) {
        _texture = texture;
    }

    Material Lambertian(Texture texture) {
        return Material(std::dynamic_pointer_cast<MaterialClass>(std::make_shared<LambertianClass>(texture)));
    }
}