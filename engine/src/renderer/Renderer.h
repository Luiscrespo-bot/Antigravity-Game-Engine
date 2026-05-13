#pragma once

#include <glad/glad.h>
#include "Light.h"
#include <vector>

namespace Engine {

    class Renderer {
    public:
        static void Init();
        static void Shutdown();

        static void BeginScene();
        static void EndScene();

        static void BeginShadowPass(const glm::vec3& lightPos, const glm::vec3& lightDir);
        static void EndShadowPass();

        static void ApplyLighting(std::shared_ptr<Shader> shader);

        static uint32_t GetShadowMapID();
        static glm::mat4 GetLightSpaceMatrix();

        static void Submit(); // For later use with VAOs and Shaders
        static void SubmitLight(const DirectionalLight& light);
        static void SubmitLight(const PointLight& light);

        static void SetClearColor(float r, float g, float b, float a);
        static void Clear();
    };

}
