#pragma once

#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Engine {

    class Model {
    public:
        Model(const std::string& path) { LoadModel(path); }
        void Draw();

    private:
        void LoadModel(const std::string& path);
        void ProcessNode(aiNode* node, const aiScene* scene);
        Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

    private:
        std::vector<Mesh> m_Meshes;
        std::string m_Directory;
    };

}
