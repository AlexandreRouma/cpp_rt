#pragma once
#include <rt/types.h>
#include <rt/rt.h>
#include <glm/glm.hpp>
#include <rt/buffer.h>

namespace rt {
    struct CameraProjection {
        Buffer<vec3l> rays;
        vec3l origin;
        vec3l direction;
        vec3l ditherX;
        vec3l ditherY;
    };

    class Camera {
    public:
        Camera();
        Camera(vec3l up, vec3l right, vec3l forward, vec3l position, double fov);
        void init(vec3l up, vec3l right, vec3l forward, vec3l position, double fov);

        void setBasis(vec3l up, vec3l right, vec3l forward);
        void setPosition(vec3l position);
        void setFOV(double fov);

        CameraProjection generateProjection(int width, int height);

    private:
        vec3l _up;
        vec3l _right;
        vec3l _forward;
        vec3l _position;
        vec3l _rotation;
        double _fov;

    };
}