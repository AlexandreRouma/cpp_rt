#pragma once
#include <rt/types.h>
#include <memory>

namespace rt {
    class ObjectClass {
    public:
        ObjectClass() {}
        virtual ~ObjectClass() {}
        virtual bool intersec();
    };

    class Object : public std::shared_ptr<ObjectClass> {
    public:
        Object() : std::shared_ptr<ObjectClass>() {}
        Object(std::shared_ptr<ObjectClass> object) : std::shared_ptr<ObjectClass>(object) {}
    };
}