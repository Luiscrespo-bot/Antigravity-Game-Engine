#include "SceneManager.h"

namespace Engine {

    std::shared_ptr<Scene> SceneManager::s_ActiveScene = nullptr;

    void SceneManager::SetScene(std::shared_ptr<Scene> scene) {
        if (s_ActiveScene)
            s_ActiveScene->OnDetach();
        
        s_ActiveScene = scene;
        
        if (s_ActiveScene)
            s_ActiveScene->OnAttach();
    }

    void SceneManager::OnUpdate(Timestep ts) {
        if (s_ActiveScene)
            s_ActiveScene->OnUpdate(ts);
    }

    void SceneManager::OnRender() {
        if (s_ActiveScene)
            s_ActiveScene->OnRender();
    }

}
