#include <rt/camera.h>
#include <glm/gtx/transform.hpp>

namespace rt {
    Camera::Camera() {}

    Camera::Camera(vec3l up, vec3l right, vec3l forward, vec3l position, double fov) {
        init(up, right, forward, position, fov);
    }

    void Camera::init(vec3l up, vec3l right, vec3l forward, vec3l position, double fov) {
        _up = up;
        _right = right;
        _forward = forward;
        _position = position;
        _fov = fov;
    }

    void Camera::setBasis(vec3l up, vec3l right, vec3l forward) {
        _up = up;
        _right = right;
        _forward = forward;
    }

    void Camera::setPosition(vec3l position) {
        _position = position;
    }

    void Camera::setFOV(double fov) {
        _fov = fov;
    }

    CameraProjection Camera::generateProjection(int width, int height) {
        CameraProjection proj;

        proj.rays = Buffer<glm::vec<3, double>>(width, height);

        double delta = 2.0 / (double)(width - 1);
        double voffset = (double)(height - 1) * delta / 2.0;
        double dist = 1.0 / tan(_fov / 2.0);

        proj.direction = _forward;
        proj.ditherX = (delta / 2.0) * _right;
        proj.ditherY = (delta / 2.0) * _up;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                proj.rays->data[(y * width) + x] = ((((double)x * delta) - 1.0) * _right) + ((voffset - ((double)y * delta)) * _up) + (dist * _forward) + _position;
            }
        }

        return proj;
    }
}