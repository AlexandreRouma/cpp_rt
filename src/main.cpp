#include <stdio.h>
#include <rt/rt.h>

#define RENDER_WIDTH    512
#define RENDER_HEIGHT   512
#define RENDER_SAMPLES  100

int main() {
    rt::Buffer<glm::vec3> renderBuf(800, 600);

    rt::Camera cam(glm::vec3(0, 1, 0), glm::vec3(1, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), 100.0);
    rt::CameraProjection proj = cam.generateProjection(800, 600);

    rt::Texture whiteWallTex = rt::texture::Solid(glm::vec3(1.0, 1.0, 1.0));
    rt::Texture orangeWallTex = rt::texture::Solid(glm::vec3(1.0, 1.0, 0.0));
    rt::Texture greenWallTex = rt::texture::Solid(glm::vec3(0.0, 1.0, 0.0));

    rt::Buffer<glm::vec3> texData = rt::Buffer<glm::vec3>::fromImage("../res/test_pattern.png");
    rt::Texture testPatternTex = rt::texture::Image(texData, rt::vec2l(1.0, 0.0), rt::vec2l(0.0, 1.0));

    rt::Material whiteWall = rt::material::Lambertian(whiteWallTex);
    rt::Material orangeWall = rt::material::Lambertian(orangeWallTex);
    rt::Material greenWall = rt::material::Lambertian(greenWallTex);
    rt::Material testPattern = rt::material::Lambertian(testPatternTex);
    rt::Material light = rt::material::LightSource(whiteWallTex, 10.0f);

    

    return 0;
}