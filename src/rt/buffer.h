#pragma once
#include <glm/glm.hpp>
#include <memory>
#include <string>

namespace rt {
    template<class T>
    class BufferClass {
    public:
        BufferClass() {}

        BufferClass(int width, int height) {
            init(width, height);
        }

        ~BufferClass() {
            if (data) { delete[] data; }
        }
        
        void init(int width, int height) {
            _width = width;
            _height = height;
            data = new T[width * height];
        }

        int getWidth() { return _width; }
        int getHeight() { return _height; }

        T* data = NULL;

    private:
        int _width = 0;
        int _height = 0;

    };

    template<class T>
    class Buffer : public std::shared_ptr<BufferClass<T>> {
    public:
        Buffer() : std::shared_ptr<BufferClass<T>>() {}
        Buffer(int width, int height) : std::shared_ptr<BufferClass<T>>(std::make_shared<BufferClass<T>>(width, height)) {}

        static Buffer fromImage(std::string path) {
            // TODO: Implement
            return Buffer();
        }
    };

}