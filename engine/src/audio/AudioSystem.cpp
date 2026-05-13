#define MINIAUDIO_IMPLEMENTATION
#include "AudioSystem.h"
#include <miniaudio.h>
#include "core/Log.h"

namespace Engine {

    static ma_engine s_AudioEngine;
    static bool s_Initialized = false;

    void AudioSystem::Init() {
        ma_result result = ma_engine_init(NULL, &s_AudioEngine);
        if (result != MA_SUCCESS) {
            ENGINE_CORE_ERROR("Failed to initialize audio engine!");
            return;
        }
        s_Initialized = true;
        ENGINE_CORE_INFO("Audio System Initialized");
    }

    void AudioSystem::Shutdown() {
        if (s_Initialized) {
            ma_engine_uninit(&s_AudioEngine);
        }
    }

    void AudioSystem::PlaySound(const std::string& filepath) {
        if (!s_Initialized) return;
        ma_engine_play_sound(&s_AudioEngine, filepath.c_str(), NULL);
    }

}
