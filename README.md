# COMP3015 – Coursework 1
## Real-Time OpenGL Scene Prototype

---

## Student Information
Module: COMP3015  
Coursework: CW1  
Author: RIYA SHAH  
Submission Year: 2025/2026  

---

## Project Overview

This project is a real-time 3D rendering prototype built using the COMP3015 Lab 1 OpenGL template. It demonstrates modern OpenGL rendering techniques including:

- Blinn–Phong lighting model
- Textured 3D model rendering
- Skybox environment mapping
- OBJ mesh loading
- Shader-based rendering pipeline

The application renders a scene containing textured models and a surrounding cubemap skybox using programmable shaders.

---

## Development Environment

- IDE: Visual Studio 2022
- Platform: Windows 10/11
- Graphics API: OpenGL 4.x Core Profile
- Build Configuration: x64

### External Libraries Used
The project includes the following libraries inside the Include and Helper directories:

- GLFW (Window and Input handling)
- GLAD (OpenGL loader)
- GLM (Mathematics library)
- stb_image (Texture loading)
- OBJMesh loader (Model loading utility)

All required headers are included locally in the project.

---

## Project Structure

comp3015 lab 1/
│
├── Helper/              # Rendering utilities (mesh, skybox, shaders, etc.)
├── Include/             # GLAD, GLFW, GLM headers
├── media/               # Models and textures
├── shaders/             # Vertex and Fragment shaders
├── src/                 # Core rendering source files
│
├── main.cpp
├── scenebasic_uniform.cpp
├── cookbookogl.cpp
├── comp3015 lab 1.sln
└── README.md

## Rendering Features

### 1. Blinn–Phong Lighting Model

Lighting is implemented in the fragment shader using the Blinn–Phong reflection model. The shader computes:

- Ambient lighting
- Diffuse lighting (Lambert term)
- Specular highlight using half-vector method

Lighting is calculated per-fragment to achieve smooth shading.

---

### 2. Texture Mapping

Textures are loaded using stb_image and applied to 3D meshes via UV coordinates. Texture sampling occurs in the fragment shader.

---

### 3. Skybox

A cubemap-based skybox is implemented using the Skybox class inside the Helper folder. This provides environmental background rendering surrounding the scene.

---

### 4. Model Loading

OBJ models are loaded using the ObjMesh utility provided in the Helper directory. Mesh data includes:

- Vertex positions
- Normals
- Texture coordinates

---

## Main Source Files

- main.cpp  
  Application entry point and scene runner.

- scenebasic_uniform.cpp  
  Core scene implementation including shader setup, lighting parameters, and draw calls.

- cookbookogl.cpp  
  Utility OpenGL helper functions.

---

## Controls

- Keyboard and mouse input handled via GLFW
- Camera movement implemented through view matrix updates

(If you used specific keys like WASD, you can add them here.)

---

## How to Build and Run

1. Open comp3015 lab 1.sln in Visual Studio
2. Set configuration to x64
3. Build the solution
4. Run the executable

Ensure that the media and shaders folders remain in the same directory as the executable.

---

## Video Demonstration

Unlisted YouTube Link:

https://youtu.be/gqvrTCSuqTs?si=h-4wdIB0H-eTEfTz

---

## Git Repository

https://github.com/riyasah0963/Comp3015-lab1

---

## Notes

This README serves as the written report for the coursework submission. It documents the technical implementation and project structure to support marking.
