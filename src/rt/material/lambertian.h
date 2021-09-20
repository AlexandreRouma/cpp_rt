#pragma once
#include <rt/buffer.h>
#include <rt/material.h>
#include <rt/texture.h>

namespace rt::material {
    class LambertianClass : public MaterialClass {
    public:
        LambertianClass(Texture texture);

        bool brdf(vec3l incident, vec3l normal, vec3l intersection, vec2l texCoord, glm::vec3 color, vec3l& outputDir, glm::vec3& outputColor);

        void setTexture(Texture texture);

    private:
        Texture _texture;

    };

    Material Lambertian(Texture texture);
}