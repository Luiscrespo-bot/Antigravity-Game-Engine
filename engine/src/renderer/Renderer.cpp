#include "Renderer.h"
#include "Framebuffer.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Engine {

    struct RendererData {
        std::vector<DirectionalLight> DirLights;
        std::vector<PointLight> PointLights;

        std::unique_ptr<Framebuffer> ShadowFramebuffer;
        glm::mat4 LightSpaceMatrix;
    };

    static RendererData s_Data;

    void Renderer::Init() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);

        FramebufferSpecification shadowSpec;
        shadowSpec.Width = 2048;
        shadowSpec.Height = 2048;
        shadowSpec.IsDepthOnly = true;
        s_Data.ShadowFramebuffer = std::make_unique<Framebuffer>(shadowSpec);
    }

    void Renderer::Shutdown() {
    }

    void Renderer::BeginScene() {
        s_Data.DirLights.clear();
        s_Data.PointLights.clear();
    }

    void Renderer::EndScene() {
    }

    void Renderer::BeginShadowPass(const glm::vec3& lightPos, const glm::vec3& lightDir) {
        float near_plane = 1.0f, far_plane = 20.0f;
        glm::mat4 lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
        glm::mat4 lightView = glm::lookAt(lightPos, lightPos + lightDir, glm::vec3(0.0f, 1.0f, 0.0f));
        s_Data.LightSpaceMatrix = lightProjection * lightView;

        s_Data.ShadowFramebuffer->Bind();
        glClear(GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::EndShadowPass() {
        s_Data.ShadowFramebuffer->Unbind();
    }

    uint32_t Renderer::GetShadowMapID() {
        return s_Data.ShadowFramebuffer->GetDepthAttachmentRendererID();
    }

    glm::mat4 Renderer::GetLightSpaceMatrix() {
        return s_Data.LightSpaceMatrix;
    }

    void Renderer::Submit() {
    }

    void Renderer::SubmitLight(const DirectionalLight& light) {
        s_Data.DirLights.push_back(light);
    }

    void Renderer::SubmitLight(const PointLight& light) {
        s_Data.PointLights.push_back(light);
    }

    void Renderer::ApplyLighting(std::shared_ptr<Shader> shader) {
        shader->Bind();
        // Shadow Mapping Data
        shader->SetMat4("u_LightSpaceMatrix", s_Data.LightSpaceMatrix);
        
        // Directional Light
        if (!s_Data.DirLights.empty()) {
            auto& light = s_Data.DirLights[0];
            shader->SetFloat3("u_DirLight.Direction", light.Direction);
            shader->SetFloat3("u_DirLight.Color", light.Color);
            shader->SetFloat("u_DirLight.Intensity", light.Intensity);
        }

        // Point Lights
        shader->SetInt("u_NumPointLights", (int)s_Data.PointLights.size());
        for (size_t i = 0; i < s_Data.PointLights.size(); i++) {
            std::string prefix = "u_PointLights[" + std::to_string(i) + "].";
            auto& light = s_Data.PointLights[i];
            shader->SetFloat3(prefix + "Position", light.Position);
            shader->SetFloat3(prefix + "Color", light.Color);
            shader->SetFloat(prefix + "Intensity", light.Intensity);
            shader->SetFloat(prefix + "Constant", light.Constant);
            shader->SetFloat(prefix + "Linear", light.Linear);
            shader->SetFloat(prefix + "Quadratic", light.Quadratic);
        }
    }

    void Renderer::SetClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
    }

    void Renderer::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

}
