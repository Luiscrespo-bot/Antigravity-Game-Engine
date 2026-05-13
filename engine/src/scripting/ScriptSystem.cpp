#include "ScriptSystem.h"
#include "core/Log.h"
#include "core/Input.h"
#include "entity/Entity.h"

namespace Engine {

    sol::state ScriptSystem::s_LuaState;

    void ScriptSystem::Init() {
        s_LuaState.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math);

        // Bind Vector3
        s_LuaState.new_usertype<glm::vec3>("Vector3",
            sol::constructors<glm::vec3(), glm::vec3(float, float, float)>(),
            "x", &glm::vec3::x,
            "y", &glm::vec3::y,
            "z", &glm::vec3::z
        );

        // Bind Input
        auto input = s_LuaState["input"].get_or_create<sol::table>();
        input["isKeyPressed"] = [](int keycode) { return Input::IsKeyPressed(keycode); };

        // Bind Entity (Simple version for now)
        s_LuaState.new_usertype<Entity>("Entity",
            "name", &Entity::Name,
            "position", &Entity::Position,
            "rotation", &Entity::Rotation,
            "scale", &Entity::Scale
        );

        ENGINE_CORE_INFO("Script System Initialized");
    }

    void ScriptSystem::Shutdown() {
    }

    void ScriptSystem::ExecuteFile(const std::string& filepath) {
        try {
            s_LuaState.script_file(filepath);
        } catch (const sol::error& e) {
            ENGINE_CORE_ERROR("Lua Error: {0}", e.what());
        }
    }

}
