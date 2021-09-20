#pragma once
#include <rt/rt.h>

namespace rt {
    class MaterialClass {
    public:
        MaterialClass() {}
        virtual ~MaterialClass() {}
        virtual bool brdf(vec3l incident, vec3l normal, vec3l intersection, vec2l texCoord, glm::vec3 color, vec3l& outputDir, glm::vec3& outputColor) = 0;
    };

    class Material : std::shared_ptr<MaterialClass> {
    public:
        Material() : std::shared_ptr<MaterialClass>() {}
        Material(std::shared_ptr<MaterialClass> material) : std::shared_ptr<MaterialClass>(material) {}
    };
}