#pragma once
#include <rt/buffer.h>
#include <rt/material.h>
#include <rt/texture.h>

namespace rt::material {
    class LightSourceClass : public MaterialClass {
    public:
        LightSourceClass(Texture texture, float intensity);

        bool brdf(vec3l incident, vec3l normal, vec3l intersection, vec2l texCoord, glm::vec3 color, vec3l& outputDir, glm::vec3& outputColor);

        void setTexture(Texture texture);
        void setIntensity(float intensity);

    private:
        Texture _texture;
        float _intensity;

    };

    Material LightSource(Texture texture, float intensity);
}