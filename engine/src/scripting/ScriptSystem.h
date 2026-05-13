#pragma once

#include <sol/sol.hpp>
#include <string>

namespace Engine {

    class ScriptSystem {
    public:
        static void Init();
        static void Shutdown();

        static void ExecuteFile(const std::string& filepath);
        
        static sol::state& GetState() { return s_LuaState; }

    private:
        static sol::state s_LuaState;
    };

}
