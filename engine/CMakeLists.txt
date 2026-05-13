set(ENGINE_SOURCES
    src/core/Application.cpp
    src/core/Window.cpp
    src/core/Log.cpp
    src/core/Input.cpp
    src/renderer/OpenGLContext.cpp
    src/renderer/Renderer.cpp
    src/renderer/OpenGLShader.cpp
    src/renderer/PerspectiveCamera.cpp
    src/renderer/Mesh.cpp
    src/renderer/Model.cpp
    src/renderer/Framebuffer.cpp
    src/scene/SceneManager.cpp
    src/scene/Scene.cpp
    src/audio/AudioSystem.cpp
    src/scripting/ScriptSystem.cpp
    src/physics/PhysicsSystem.cpp
    src/ui/UISystem.cpp
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

set(ENGINE_HEADERS
    src/core/Application.h
    src/core/Window.h
    src/core/Log.h
    src/core/Core.h
    src/core/Timestep.h
    src/core/Input.h
    src/core/KeyCodes.h
    src/core/ResourceManager.h
    src/renderer/GraphicsContext.h
    src/renderer/OpenGLContext.h
    src/renderer/Renderer.h
    src/renderer/Shader.h
    src/renderer/OpenGLShader.h
    src/renderer/Camera.h
    src/renderer/PerspectiveCamera.h
    src/renderer/Mesh.h
    src/renderer/Model.h
    src/renderer/Framebuffer.h
    src/renderer/Light.h
    src/renderer/Material.h
    src/scene/Scene.h
    src/scene/SceneManager.h
    src/entity/Entity.h
    src/audio/AudioSystem.h
    src/scripting/ScriptSystem.h
    src/physics/PhysicsSystem.h
    src/ui/UISystem.h
)

add_library(Engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

target_include_directories(Engine PUBLIC 
    src 
    ${miniaudio_SOURCE_DIR} 
    ${sol2_SOURCE_DIR}/include
    ${imgui_SOURCE_DIR}
    ${imgui_SOURCE_DIR}/backends
    ${assimp_SOURCE_DIR}/include
    ${assimp_BINARY_DIR}/include
)
target_link_libraries(Engine PUBLIC glfw spdlog::spdlog glad glm lua assimp)

# OpenGL linkage
if(WIN32)
    target_link_libraries(Engine PUBLIC opengl32)
endif()
