#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "core/Timestep.h"

namespace Engine {

    class Entity;

    struct AABB {
        glm::vec3 Min;
        glm::vec3 Max;
    };

    class PhysicsSystem {
    public:
        static void Init();
        static void OnUpdate(Timestep ts, std::vector<std::shared_ptr<Entity>>& entities);

        static bool CheckCollision(const AABB& a, const AABB& b);

    private:
        static glm::vec3 s_Gravity;
    };

}
