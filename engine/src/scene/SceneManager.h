#pragma once

#include "Scene.h"
#include <memory>
#include <vector>

namespace Engine {

    class SceneManager {
    public:
        static void SetScene(std::shared_ptr<Scene> scene);
        
        static void OnUpdate(Timestep ts);
        static void OnRender();

    private:
        static std::shared_ptr<Scene> s_ActiveScene;
    };

}
