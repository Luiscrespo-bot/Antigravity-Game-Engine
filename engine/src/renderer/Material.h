#pragma once

#include <glm/glm.hpp>
#include <memory>
#include "Shader.h"

namespace Engine {

    struct Material {
        glm::vec3 Ambient;
        glm::vec3 Diffuse;
        glm::vec3 Specular;
        float Shininess;

        std::shared_ptr<Shader> ShaderPtr;

        Material(std::shared_ptr<Shader> shader)
            : ShaderPtr(shader), Ambient(1.0f), Diffuse(1.0f), Specular(0.5f), Shininess(32.0f) {}
    };

}
