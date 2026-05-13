#include "PhysicsSystem.h"
#include "entity/Entity.h"

namespace Engine {

    glm::vec3 PhysicsSystem::s_Gravity = { 0.0f, -9.81f, 0.0f };

    void PhysicsSystem::Init() {
    }

    void PhysicsSystem::OnUpdate(Timestep ts, std::vector<std::shared_ptr<Entity>>& entities) {
        for (auto& entity : entities) {
            // Simple gravity application if we assume entities have a 'Velocity'
            // For now, let's just move them down
            entity->Position += s_Gravity * (float)ts;
        }
    }

    bool PhysicsSystem::CheckCollision(const AABB& a, const AABB& b) {
        return (a.Min.x <= b.Max.x && a.Max.x >= b.Min.x) &&
               (a.Min.y <= b.Max.y && a.Max.y >= b.Min.y) &&
               (a.Min.z <= b.Max.z && a.Max.z >= b.Min.z);
    }

}
