#pragma once

#include <string>

namespace Engine {

    class AudioSystem {
    public:
        static void Init();
        static void Shutdown();

        static void PlaySound(const std::string& filepath);
    };

}
