#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>

namespace Engine {

    struct Vertex {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
    };

    class Mesh {
    public:
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
        void Draw();

    private:
        void SetupMesh();

    private:
        std::vector<Vertex> m_Vertices;
        std::vector<unsigned int> m_Indices;
        unsigned int m_VAO, m_VBO, m_EBO;
    };

}
