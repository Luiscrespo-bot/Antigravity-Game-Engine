# 🌌 Antigravity Engine

**Antigravity Engine** is a high-performance, modular, and scalable 3D game engine built from scratch using C++ and OpenGL. Designed with a "mini-OS" philosophy, it features a decoupled architecture where every system is an independent module.

![C++](https://img.shields.io/badge/Language-C%2B%2B20-blue.svg)
![OpenGL](https://img.shields.io/badge/Renderer-OpenGL%204.1-orange.svg)
![Build](https://img.shields.io/badge/Build-CMake-green.svg)
![License](https://img.shields.io/badge/License-MIT-lightgrey.svg)

## 🚀 Features

### 🎮 Core & Systems
- **Modular Architecture**: Systems are decoupled and communicate via clean interfaces.
- **Game Loop**: Professional loop with fixed/variable delta-time (`Timestep`).
- **Input System**: Static wrapper for GLFW with easy-to-use API.
- **Resource Manager**: Centralized asset management to prevent memory duplication.
- **Logging**: High-performance logging via `spdlog`.

### 🎨 Rendering (OpenGL)
- **3D Renderer**: Perspective camera system with view-projection matrices.
- **Lighting**: Phong lighting model with support for Directional and Point lights.
- **Shadow Mapping**: Dynamic shadows using depth-only framebuffers.
- **Model Loading**: Import complex 3D assets (`.fbx`, `.obj`, `.gltf`) using **Assimp**.
- **Material System**: Customizable material properties (Ambient, Diffuse, Specular, Shininess).

### 🛠 Tools & Scripting
- **Editor UI**: Integrated **Dear ImGui** with Docking and Viewports support.
  - **Light Editor**: Real-time adjustment of scene lighting.
  - **Inspector**: Real-time entity transformation editing.
  - **Debug Panel**: Performance statistics and GPU information.
- **Scripting**: **Lua** integration via `sol2` to control entity behavior dynamically.
- **Audio**: Pro-grade audio management using **miniaudio**.

## 🛠 Tech Stack

| Component | Technology |
|-----------|------------|
| **Language** | C++20 |
| **Graphics API** | OpenGL 4.1 |
| **Windowing** | GLFW 3.3 |
| **OpenGL Loader** | GLAD |
| **Math** | GLM |
| **UI** | Dear ImGui |
| **Scripting** | Lua 5.4 + sol2 |
| **Audio** | miniaudio |
| **Model Loading** | Assimp 5.2 |
| **Logging** | spdlog |

## 📂 Project Structure

```text
/engine          # Core Engine Source
  /core          # Application, Window, Input, Logging
  /renderer      # OpenGL abstractions, Mesh, Model, Lights
  /scene         # Scene management and graph
  /entity        # Entity base classes
  /audio         # Audio system (miniaudio)
  /scripting     # Lua integration (sol2)
  /ui            # ImGui integration and Editor tools
  /physics       # Basic physics and AABB collisions
/game            # Sandbox/Client application
/assets          # Textures, Models, Shaders, Scripts
/extern          # External dependencies (Fetched via CMake)
```

## ⚙️ Building the Engine

### Prerequisites
- **CMake** (v3.20+)
- A C++20 compliant compiler (MSVC, GCC, Clang)
- Graphics driver with OpenGL 4.1 support

### Compilation
1. Clone the repository:
   ```bash
   git clone https://github.com/youruser/antigravity-engine.git
   cd antigravity-engine
   ```
2. Create build directory:
   ```bash
   mkdir build && cd build
   ```
3. Generate project files and build:
   ```bash
   cmake ..
   cmake --build .
   ```

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
*Built with ❤️ by [Luis Fernando Crespo Soliz/Antigravity Game Engine Team]*
