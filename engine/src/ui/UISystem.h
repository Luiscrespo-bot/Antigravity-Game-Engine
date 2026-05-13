#pragma once

#include "core/Timestep.h"
#include <string>
#include <vector>

namespace Engine {

    class Entity;

    class UISystem {
    public:
        static void Init(void* window);
        static void Shutdown();

        static void Begin();
        static void End();

        // UI Modules
        static void DrawDebugPanel();
        static void DrawInspector(Entity* entity);
        static void DrawConsole();
        static void DrawLightEditor(DirectionalLight& dirLight, std::vector<PointLight>& pointLights);

    private:
        static bool s_ShowDebugPanel;
        static bool s_ShowInspector;
        static bool s_ShowConsole;
    };

}
