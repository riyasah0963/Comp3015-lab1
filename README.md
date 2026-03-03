# COMP3015 – Computer Graphics  
## Coursework 1 – Lighting & Shading (Lab 3)

### 👨‍🎓 Student Information
- Name: RIYA SHAH
- Student ID: 10816845
- Module: COMP3015
- Coursework: CW1 – Lighting &

  📌 Overview

This project implements a Skybox in OpenGL using cubemap textures.

A skybox creates the illusion of an infinite 3D environment by mapping six textures onto the inside of a cube that surrounds the scene. The skybox remains visually distant and forms the background of the rendered scene.

⸻

🎯 Objectives

The objectives of this lab were:
	•	Create a SkyBox class
	•	Load and bind cubemap textures
	•	Implement skybox vertex and fragment shaders
	•	Render the skybox correctly using OpenGL
	•	Handle depth testing appropriately

⸻

🧊 SkyBox Implementation

A dedicated SkyBox class was created to manage:
	•	Vertex Array Object (VAO)
	•	Vertex Buffer Object (VBO)
	•	Cubemap texture loading
	•	Rendering logic

The cube is defined using 36 vertices (6 faces × 2 triangles × 3 vertices).

⸻

🖼 Cubemap Textures

The skybox uses six images corresponding to the faces of a cube:
	•	Positive X
	•	Negative X
	•	Positive Y
	•	Negative Y
	•	Positive Z
	•	Negative Z

These textures are loaded using stb_image and assigned using:

GL_TEXTURE_CUBE_MAP_POSITIVE_X + i

The textures are stored in:

media/texture/cube/

🎨 Shader Implementation

Vertex Shader

The vertex shader:
	•	Accepts cube vertex positions
	•	Removes translation from the view matrix:

  mat4 viewNoTranslate = mat4(mat3(View));
  This ensures the skybox remains visually distant and does not translate with the scene.

  It also uses:

  gl_Position = pos.xyww;
  This ensures the skybox is rendered at maximum depth.

  Fragment Shader

The fragment shader:
	•	Uses samplerCube
	•	Samples from the cubemap texture
	•	Outputs the final environment color

⸻

⚙️ Depth Handling

To ensure the skybox renders correctly behind all other objects, the depth function is temporarily changed:

glDepthFunc(GL_LEQUAL);
After rendering the skybox, it is reset to:

glDepthFunc(GL_LESS);
This ensures proper depth testing behavior.

🔧 Important Implementation Detail

The SkyBox object is initialized inside initScene() rather than the constructor.

Reason:

OpenGL functions such as glGenBuffers() require an active OpenGL context.
Initializing the SkyBox before context creation caused runtime errors.
Moving initialization to initScene() resolved this issue.

⸻

🐞 Issues Encountered

During development, the following issues were encountered:
	•	Linker errors due to constructor mismatch
	•	Multiple definition errors from stb_image
	•	Access violation caused by calling OpenGL functions before context initialization

All issues were resolved by:
	•	Matching header and source declarations
	•	Defining STB_IMAGE_IMPLEMENTATION only once
	•	Creating the SkyBox after OpenGL context initialization

⸻

▶️ How to Run
	1.	Open the project in Visual Studio
	2.	Ensure the media folder is located in the project directory
	3.	Build → Rebuild Solution
	4.	Press F5 to run

The skybox will render as the background environment.

⸻

✅ Final Result

The final implementation successfully:
	•	Loads cubemap textures
	•	Binds them to GL_TEXTURE_CUBE_MAP
	•	Renders a surrounding skybox
	•	Uses correct shader logic
	•	Handles depth testing properly

This completes the Lab 4 skybox implementation.


## 🔗 
GitHub Repository

Repository link:
https://github.com/riyasah0963/Comp3015-lab1

---
