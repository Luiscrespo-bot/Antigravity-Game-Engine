#pragma once

#include "core/Timestep.h"
#include "entity/Entity.h"
#include <vector>
#include <memory>

namespace Engine {

    class Scene {
    public:
        Scene() = default;
        virtual ~Scene() = default;

        virtual void OnUpdate(Timestep ts);
        virtual void OnRender();

        virtual void OnAttach() {}
        virtual void OnDetach() {}

        void AddEntity(std::shared_ptr<Entity> entity) { m_Entities.push_back(entity); }

    protected:
        std::vector<std::shared_ptr<Entity>> m_Entities;
    };

}
