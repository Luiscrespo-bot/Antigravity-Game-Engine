#include "UISystem.h"
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include "entity/Entity.h"

namespace Engine {

    bool UISystem::s_ShowDebugPanel = true;
    bool UISystem::s_ShowInspector = true;
    bool UISystem::s_ShowConsole = true;

    void UISystem::Init(void* window) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(window), true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void UISystem::Shutdown() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void UISystem::Begin() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void UISystem::End() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        ImGuiIO& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void UISystem::DrawDebugPanel() {
        ImGui::Begin("Debug Panel", &s_ShowDebugPanel);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::Separator();
        ImGui::Text("GPU Info:");
        ImGui::Text("Vendor: %s", glGetString(GL_VENDOR));
        ImGui::End();
    }

    void UISystem::DrawInspector(Entity* entity) {
        ImGui::Begin("Inspector", &s_ShowInspector);
        if (entity) {
            ImGui::Text("Name: %s", entity->Name.c_str());
            ImGui::DragFloat3("Position", &entity->Position.x, 0.1f);
            ImGui::DragFloat3("Rotation", &entity->Rotation.x, 0.1f);
            ImGui::DragFloat3("Scale", &entity->Scale.x, 0.1f);
        } else {
            ImGui::Text("No entity selected");
        }
        ImGui::End();
    }

    void UISystem::DrawConsole() {
        ImGui::Begin("Console", &s_ShowConsole);
        ImGui::Text("Welcome to Antigravity Engine Console!");
        // Simplified console logic
        static char input[256] = "";
        if (ImGui::InputText("Command", input, sizeof(input), ImGuiInputTextFlags_EnterReturnsTrue)) {
            // Process command
            input[0] = '\0';
        }
        ImGui::End();
    }

    void UISystem::DrawLightEditor(DirectionalLight& dirLight, std::vector<PointLight>& pointLights) {
        ImGui::Begin("Lighting Editor");
        
        if (ImGui::CollapsingHeader("Directional Light")) {
            ImGui::DragFloat3("Direction", &dirLight.Direction.x, 0.01f);
            ImGui::ColorEdit3("Color", &dirLight.Color.x);
            ImGui::DragFloat("Intensity", &dirLight.Intensity, 0.1f, 0.0f, 10.0f);
        }

        if (ImGui::CollapsingHeader("Point Lights")) {
            for (size_t i = 0; i < pointLights.size(); i++) {
                std::string label = "Light " + std::to_string(i);
                if (ImGui::TreeNode(label.c_str())) {
                    ImGui::DragFloat3("Position", &pointLights[i].Position.x, 0.1f);
                    ImGui::ColorEdit3("Color", &pointLights[i].Color.x);
                    ImGui::DragFloat("Intensity", &pointLights[i].Intensity, 0.1f, 0.0f, 10.0f);
                    ImGui::DragFloat("Linear", &pointLights[i].Linear, 0.001f, 0.0f, 1.0f);
                    ImGui::DragFloat("Quadratic", &pointLights[i].Quadratic, 0.0001f, 0.0f, 1.0f);
                    ImGui::TreePop();
                }
            }
        }

        ImGui::End();
    }

}
