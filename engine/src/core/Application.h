#pragma once

#include "Core.h"
#include "Window.h"
#include "Timestep.h"

namespace Engine {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();

        inline Window& GetWindow() { return *m_Window; }
        inline static Application& Get() { return *s_Instance; }

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        float m_LastFrameTime = 0.0f;
    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication();

}
