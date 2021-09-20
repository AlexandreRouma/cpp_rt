#pragma once
#include <glm/glm.hpp>

namespace rt {
    typedef glm::vec<2, double> vec2l;
    typedef glm::vec<3, double> vec3l;
    typedef glm::vec<4, double> vec4l;

    struct Ray {
        vec3l direction;
        vec3l origin;
    };
}