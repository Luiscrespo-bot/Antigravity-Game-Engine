#include "Application.h"
#include <GLFW/glfw3.h>
#include "renderer/Renderer.h"
#include "scene/SceneManager.h"
#include "audio/AudioSystem.h"
#include "scripting/ScriptSystem.h"
#include "ui/UISystem.h"

namespace Engine {

    Application* Application::s_Instance = nullptr;

    Application::Application() {
        ENGINE_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        Renderer::Init();
        AudioSystem::Init();
        ScriptSystem::Init();
        UISystem::Init(m_Window->GetNativeWindow());
    }

    Application::~Application() {
        UISystem::Shutdown();
        ScriptSystem::Shutdown();
        AudioSystem::Shutdown();
    }

    void Application::Run() {
        while (m_Running) {
            float time = (float)glfwGetTime();
            Timestep timestep = time - m_LastFrameTime;
            m_LastFrameTime = time;

            Renderer::SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            Renderer::Clear();

            SceneManager::OnUpdate(timestep);
            SceneManager::OnRender();

            UISystem::Begin();
            UISystem::DrawDebugPanel();
            UISystem::DrawConsole();
            UISystem::DrawInspector(nullptr); // Pass selected entity here later
            UISystem::End();
            
            m_Window->OnUpdate();
        }
    }

}
