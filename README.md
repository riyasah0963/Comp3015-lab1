🎮 OpenGL Setup Library

This repository contains the required OpenGL supporting libraries and header files used for building graphics-based applications using C/C++ and OpenGL.

It includes GLM (OpenGL Mathematics) and GLFW library files which help in window creation, input handling, and mathematical operations required in graphics programming.

📂 Project Structure
openGL/
│
├── Include/
│   ├── glm/          → OpenGL Mathematics Library
│   ├── KHR/          → Khronos platform headers
│
├── lib/
│   └── glfw3.lib     → GLFW library file

🧾 Libraries Included
✅ GLM (OpenGL Mathematics)

GLM is a header-only C++ mathematics library for graphics software.

It provides:

Vector operations

Matrix transformations

Quaternion support

Geometry calculations

Official Website: https://glm.g-truc.net/

✅ GLFW

GLFW is used for:

Creating windows

Handling keyboard and mouse input

Managing OpenGL context

Official Website: https://www.glfw.org/

⚙️ Requirements

Make sure you have installed:

C++ Compiler (GCC / MinGW / MSVC)

OpenGL Supported GPU

IDE (CodeBlocks, Visual Studio, VS Code, etc.)

🚀 How To Use
Step 1: Add Include Path

Add the Include folder in your compiler settings.

Example:

openGL/Include

Step 2: Add Library Path

Add the lib folder in linker settings.

Example:

openGL/lib

Step 3: Link GLFW Library

While compiling, link:

glfw3
opengl32
gdi32

💡 Example Compile Command (MinGW)
g++ main.cpp -IopenGL/Include -LopenGL/lib -lglfw3 -lopengl32 -lgdi32 -o app

🎯 Purpose

This repository helps developers quickly set up OpenGL projects without manually downloading and configuring dependencies.
