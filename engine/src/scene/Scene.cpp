#include "Scene.h"
#include "physics/PhysicsSystem.h"

namespace Engine {

    void Scene::OnUpdate(Timestep ts) {
        PhysicsSystem::OnUpdate(ts, m_Entities);

        for (auto& entity : m_Entities) {
            entity->OnUpdate(ts);
        }
    }

    void Scene::OnRender() {
        for (auto& entity : m_Entities) {
            entity->OnRender();
        }
    }

}
