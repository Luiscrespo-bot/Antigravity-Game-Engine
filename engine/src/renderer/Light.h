#pragma once

#include <glm/glm.hpp>

namespace Engine {

    struct DirectionalLight {
        glm::vec3 Direction;
        glm::vec3 Color;
        float Intensity;

        DirectionalLight()
            : Direction(-0.2f, -1.0f, -0.3f), Color(1.0f), Intensity(1.0f) {}
    };

    struct PointLight {
        glm::vec3 Position;
        glm::vec3 Color;
        float Intensity;
        float Constant;
        float Linear;
        float Quadratic;

        PointLight()
            : Position(0.0f), Color(1.0f), Intensity(1.0f), Constant(1.0f), Linear(0.09f), Quadratic(0.032f) {}
    };

}
