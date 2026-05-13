#pragma once

#include <string>
#include <unordered_map>
#include <memory>

namespace Engine {

    // Forward declarations
    class Texture;
    class Shader;

    class ResourceManager {
    public:
        static void Init();
        static void Shutdown();

        // Placeholder for now as we haven't implemented Shader/Texture classes yet
        // static std::shared_ptr<Shader> LoadShader(const std::string& name, const std::string& filepath);
        // static std::shared_ptr<Texture> LoadTexture(const std::string& name, const std::string& filepath);

        // static std::shared_ptr<Shader> GetShader(const std::string& name);
        // static std::shared_ptr<Texture> GetTexture(const std::string& name);

    private:
        // static std::unordered_map<std::string, std::shared_ptr<Shader>> s_Shaders;
        // static std::unordered_map<std::string, std::shared_ptr<Texture>> s_Textures;
    };

}
