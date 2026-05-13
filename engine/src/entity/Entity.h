#pragma once

#include <glm/glm.hpp>
#include "core/Timestep.h"
#include <string>

namespace Engine {

    class Entity {
    public:
        Entity(const std::string& name = "Entity")
            : Name(name), Position(0.0f), Rotation(0.0f), Scale(1.0f) {}
        virtual ~Entity() = default;

        virtual void OnUpdate(Timestep ts) {}
        virtual void OnRender() {}

    public:
        std::string Name;
        glm::vec3 Position;
        glm::vec3 Rotation;
        glm::vec3 Scale;
    };

}
