#include <core/Application.h>

class Sandbox : public Engine::Application {
public:
    Sandbox() {
    }

    ~Sandbox() {
    }
};

Engine::Application* Engine::CreateApplication() {
    return new Sandbox();
}

int main() {
    Engine::Log::Init();
    ENGINE_CORE_INFO("Initialized Log!");

    auto app = Engine::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
