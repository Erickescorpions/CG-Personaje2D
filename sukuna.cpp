
#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>

//clases para dar orden y limpieza al c�digo
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"

//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
Window mainWindow;

std::vector<MeshColor*> meshColorList;
std::vector<Shader>shaderList;

//Vertex Shader
static const char* vShaderPersonaje = "shaders/shaderpersonaje.vert";
static const char* fShaderPersonaje = "shaders/shaderpersonaje.frag";


void CrearFiguras()
{
	GLfloat vertices_triangulorojo[] = {
		//X			Y			Z			R		G		B
		-1.0f,	-1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
		1.0f,	-1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
		0.0f,	1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
		
	};

	MeshColor* triangulorojo = new MeshColor();
	triangulorojo->CreateMeshColor(vertices_triangulorojo, 18);
	meshColorList.push_back(triangulorojo);

	GLfloat vertices_cuadradoverde[] = {
		//X			Y			Z			R		G		B
		-0.5f,	-0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
		0.5f,	-0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
		0.5f,	0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
		-0.5f,	-0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
		0.5f,	0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
		-0.5f,	0.5f,		0.5f,			0.0f,	1.0f,	0.0f,

	};

	MeshColor* cuadradoverde = new MeshColor();
	cuadradoverde->CreateMeshColor(vertices_cuadradoverde, 36);
	meshColorList.push_back(cuadradoverde);

	// color de piel sin sombra = 1.0f, 0.9529f, 0.8902f,
	// color piel con sombra = 0.9843f, 0.6392f, 0.549f, 
	// color bufanda y calcetines = 0.2267f, 0.102f, 0.0941f,
	// color cabello rapado = 0.2196f, 0.0784f, 0.0863f,
	// color cabello rosa clarito = 1.0f, 0.6157f, 0.6118f,

	GLfloat sukunaColorVertices[] = {
		// bufanda 
		-0.19f, -0.12f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.04f, -0.12f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		-0.19f, -0.12f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.23f, -0.14f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		-0.23f, -0.14f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.24f, -0.18f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		-0.24f, -0.18f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.22f, -0.22f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		-0.22f, -0.22f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.18f, -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		-0.18f, -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.14f, -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		-0.14f, -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.19f, -0.12f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.05f, -0.24f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		-0.05f, -0.24f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.06f,  -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		0.06f,  -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.12f, -0.22f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		0.12f, -0.22f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.16f, -0.18f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		0.16f, -0.18f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.13f, -0.15f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		0.13f, -0.15f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.04f, -0.12f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,

		/*-0.19f, -0.12f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.23f, -0.14f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.24f, -0.18f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.22f, -0.22f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.18f, -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.14f, -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.1f, -0.2f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		-0.05f, -0.24f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.06f,  -0.23f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.12f, -0.22f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.16f, -0.18f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.13f, -0.15f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		0.04f, -0.12f, 0.0f, 0.2267f, 0.102f, 0.0941f,
		*/

		// orejita
		-0.22f, -0.09f, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.3f, -0.1f, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.3f, -0.1f, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.38f, -0.08f, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.38f, -0.08f, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.43f, -0.03f, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.43f, -0.03f, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.47f, 0.07, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.47f, 0.07, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.45f, 0.15, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.45f, 0.15, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.38f, 0.17, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.38f, 0.17, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.29f, 0.11, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.29f, 0.11, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.27f, 0.03, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.22f, -0.09f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.27f, 0.03, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		/*-0.22f, -0.09f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.3f, -0.1f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.38f, -0.08f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.43f, -0.03f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.47f, 0.07, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.45f, 0.15, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.38f, 0.17, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.29f, 0.11, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.27f, 0.03, 0.0f, 1.0f, 0.9529f, 0.8902f,*/

		// rostro sin sombra
		-0.19f, -0.12f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.2f, -0.13f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.2f, -0.13f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.22f, -0.09f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.22f, -0.09f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.27f, 0.03, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.27f, 0.03, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.24f, 0.05, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.24f, 0.05, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.18f, 0.02, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.18f, 0.02, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.2f, 0.1, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		0.2f, 0.1, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.38f, 0.17, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		0.38f, 0.17, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.38f, 0.02, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		0.38f, 0.02, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.3f, -0.07f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		
		0.3f, -0.07f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.13f, -0.15f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		0.13f, -0.15f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.04f, -0.12f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.19f, -0.12f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.04f, -0.12f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.0f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,


		/*
		-0.19f, -0.12f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.2f, -0.13f, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.22f, -0.09f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		-0.27f, 0.03, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.24f, 0.05, 0.0f,  1.0f, 0.9529f, 0.8902f,
		-0.18f, 0.02, 0.0f,  1.0f, 0.9529f, 0.8902f,
		0.2f, 0.1, 0.0f,  1.0f, 0.9529f, 0.8902f,
		0.38f, 0.17, 0.0f,  1.0f, 0.9529f, 0.8902f,
		0.38f, 0.02, 0.0f,  1.0f, 0.9529f, 0.8902f,
		0.3f, -0.07f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.13f, -0.15f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		0.04f, -0.12f, 0.0f, 1.0f, 0.9529f, 0.8902f,

		-0.3f, 0.0f, 0.0f, 1.0f, 0.9529f, 0.8902f,
		*/

		// rostro con sombra

		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.4f, 0.41, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f,0.1f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.4f, 0.41, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.42f, 0.35, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.42f, 0.35, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.41f, 0.28, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		
		0.41f, 0.28, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.38f, 0.2, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.38f, 0.2, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.38f, 0.17, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.38f, 0.17, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.2f, 0.1, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.2f, 0.1, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.18f, 0.02, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.18f, 0.02, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.24f, 0.05, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.24f, 0.05, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.27f, 0.03, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.27f, 0.03, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.29f, 0.11, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.29f, 0.11, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.4f, 0.41, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.3f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		/*
		
		0.1f, 0.3f,  0.0f, 0.9843f, 0.6392f, 0.549f,
		0.4f, 0.41, 0.0f,  0.9843f, 0.6392f, 0.549f,
		0.42f, 0.35, 0.0f,  0.9843f, 0.6392f, 0.549f,
		0.41f, 0.28, 0.0f,  0.9843f, 0.6392f, 0.549f,
		0.38f, 0.2, 0.0f,  0.9843f, 0.6392f, 0.549f,
		0.38f, 0.17, 0.0f,  0.9843f, 0.6392f, 0.549f,
		0.2f, 0.1, 0.0f,  0.9843f, 0.6392f, 0.549f,
		-0.18f, 0.02, 0.0f,  0.9843f, 0.6392f, 0.549f,
		-0.24f, 0.05, 0.0f,  0.9843f, 0.6392f, 0.549f,
		-0.27f, 0.03, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.29f, 0.11, 0.0f, 0.9843f, 0.6392f, 0.549f,
		*/

		// raiz del cabello
		-0.29f, 0.11, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.27f, 0.13f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.27f, 0.13f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.3f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.3f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.26f, 0.22f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		// 
		-0.26f, 0.22f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.29f, 0.25f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.29f, 0.25f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.25f, 0.29f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.25f, 0.29f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.29f, 0.31f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.25f, 0.35f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.25f, 0.29f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.25f, 0.35f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.2f, 0.33f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.2f, 0.33f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.25f, 0.29f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.2f, 0.33f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.21f, 0.39f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.21f, 0.39f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.1f, 0.38f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.1f, 0.38f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.12f, 0.43f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.03f, 0.41f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.1f, 0.38f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.03f, 0.41f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.03f, 0.41f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.03f, 0.47f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.07f, 0.44f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		-0.03f, 0.41f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.07f, 0.44f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.07f, 0.44f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.5f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.11f, 0.43f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.07f, 0.44f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.11f, 0.43f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.11f, 0.43f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.17f, 0.48f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.18f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.11f, 0.43f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.18f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.18f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.24f, 0.49f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.23f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.18f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.23f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.23f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.34f, 0.49f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.33f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.23f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.33f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.33f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.36f, 0.46f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.4f, 0.41, 0.0f, 0.9843f, 0.6392f, 0.549f,

		0.33f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.4f, 0.41, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.0f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,

		/*
		-0.29f, 0.11, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.27f, 0.13f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.3f, 0.2f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.26f, 0.22f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.29f, 0.25f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.25f, 0.29f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.29f, 0.31f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.25f, 0.35f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.2f, 0.33f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.21f, 0.39f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.1f, 0.38f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.12f, 0.43f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.03f, 0.41f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		-0.03f, 0.47f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.07f, 0.44f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.1f, 0.5f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.11f, 0.43f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.17f, 0.48f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.18f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.24f, 0.49f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.23f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.34f, 0.49f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.33f, 0.42f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.36f, 0.46f, 0.0f, 0.9843f, 0.6392f, 0.549f,
		0.4f, 0.41, 0.0f,  0.9843f, 0.6392f, 0.549f,
		*/

		// cabello parte rapada
			
		-0.29f, 0.11, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.27f, 0.13f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.3f, 0.2f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.29f, 0.11, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.3f, 0.2f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.5f, 0.19f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.45f, 0.15, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.5f, 0.19f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.5f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.44f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.44f, 0.31f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.5f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.44f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.5f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.35f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.37f, 0.32f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.44f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.35f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.44f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.35f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.37f, 0.32f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.44f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.29f, 0.31f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.32f, 0.34f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.35f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.29f, 0.31f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.35f, 0.27f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.3f, 0.2f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.26f, 0.22f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.29f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.3f, 0.2f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.29f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.29f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.25f, 0.29f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.29f, 0.31f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.29f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.29f, 0.31f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		/*
		
		-0.29f, 0.31f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.32f, 0.34f, 0.0f,  0.2196f, 0.0784f, 0.0863f,
		-0.35f, 0.27f, 0.0f,  0.2196f, 0.0784f, 0.0863f,
		-0.37f, 0.32f, 0.0f,  0.2196f, 0.0784f, 0.0863f,
		-0.44f, 0.27f, 0.0f,  0.2196f, 0.0784f, 0.0863f,
		-0.44f, 0.31f, 0.0f,  0.2196f, 0.0784f, 0.0863f,
		-0.5f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.5f, 0.19f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.45f, 0.15, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.38f, 0.17f, 0.0f, 0.2196f, 0.0784f, 0.0863f,

		-0.29f, 0.11, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.27f, 0.13f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.3f, 0.2f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.26f, 0.22f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.29f, 0.25f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.25f, 0.29f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		-0.29f, 0.31f, 0.0f, 0.2196f, 0.0784f, 0.0863f,
		*/

		// parte rosa clarito 

			0.4f, 0.47f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.5f, 0.41f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.4f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.4f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.38f, 0.54f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.32f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.32f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.32f, 0.58f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.22f, 0.54f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.22f, 0.54f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.2f, 0.6f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.11f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.11f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.07f, 0.6f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.04f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.04f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.09f, 0.55f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.09f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.09f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.2f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.2f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.2f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.24f, 0.45f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.25f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.25f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.28f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.32f, 0.34f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.32f, 0.34f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.29f, 0.31f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.25f, 0.35f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.25f, 0.35f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.2f, 0.33f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.21f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.21f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.1f, 0.38f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.12f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.12f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.03f, 0.41f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.03f, 0.47f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.03f, 0.47f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.07f, 0.44f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.1f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.1f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.11f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.17f, 0.48f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.17f, 0.48f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.18f, 0.42f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.24f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.24f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.23f, 0.42f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.34f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.34f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.33f, 0.42f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.36f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.36f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.4f, 0.41, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.4f, 0.47f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.4f, 0.47f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.4f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.36f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.36f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.4f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.34f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.34f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.4f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.32f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.34f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.32f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.24f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.32f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.24f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.22f, 0.54f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.24f, 0.49f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.22f, 0.54f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.17f, 0.48f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.22f, 0.54f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.17f, 0.48f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.11f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.17f, 0.48f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.11f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.1f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.11f, 0.52f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.1f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.04f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.1f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			0.04f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.03f, 0.47f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			0.04f, 0.5f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.03f, 0.47f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.09f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.03f, 0.47f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.09f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.12f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.09f, 0.46f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.12f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.2f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.12f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.2f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.21f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.2f, 0.43f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.21f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.25f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,

			-0.21f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.25f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.25f, 0.35f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			
			-0.25f, 0.39f, 0.0f, 1.0f, 0.8745f, 0.8941f,
			-0.25f, 0.35f, 0.0f, 1.0f, 0.8745f, 0.8941f,			
			-0.32f, 0.34f, 0.0f, 1.0f, 0.8745f, 0.8941f,
		/*
		
		0.4f, 0.47f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.5f, 0.41f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.4f, 0.5f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.38f, 0.54f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.32f, 0.52f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.32f, 0.58f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.22f, 0.54f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.2f, 0.6f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.11f, 0.52f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.07f, 0.6f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		0.04f, 0.5f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		-0.09f, 0.55f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		-0.09f, 0.46f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		-0.2f, 0.49f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		-0.2f, 0.43f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		-0.24f, 0.45f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		-0.25f, 0.39f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		-0.28f, 0.43f, 0.0f,  1.0f, 0.6157f, 0.6118f,
		-0.32f, 0.34f, 0.0f,  1.0f, 0.6157f, 0.6118f,

		-0.29f, 0.31f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		-0.25f, 0.35f, 0.0f, 1.0f, 0.6157f, 0.118f,
		-0.2f, 0.33f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		-0.21f, 0.39f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		-0.1f, 0.38f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		-0.12f, 0.43f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		-0.03f, 0.41f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		-0.03f, 0.47f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.07f, 0.44f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.1f, 0.5f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.11f, 0.43f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.17f, 0.48f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.18f, 0.42f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.24f, 0.49f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.23f, 0.42f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.34f, 0.49f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.33f, 0.42f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.36f, 0.46f, 0.0f, 1.0f, 0.6157f, 0.6118f,
		0.4f, 0.41, 0.0f, 1.0f, 0.6157f, 0.6118f,
		
		*/

		// cabello rosa fuerte 1.0f, 0.502f, 0.4941f,
		//0.3f, 0.6f, 0.0f, 1.0f, 0.502f, 0.4941f,
		
		0.5f, 0.41f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.4f, 0.5f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.38f, 0.54f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.38f, 0.54f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.32f, 0.52f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.32f, 0.58f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.32f, 0.58f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.22f, 0.54f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.2f, 0.6f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.2f, 0.6f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.11f, 0.52f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.07f, 0.6f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.07f, 0.6f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.04f, 0.5f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.09f, 0.55f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.09f, 0.55f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.09f, 0.46f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.2f, 0.49f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.2f, 0.49f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.2f, 0.43f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.24f, 0.45f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.24f, 0.45f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.25f, 0.39f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.28f, 0.43f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.28f, 0.43f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.32f, 0.34f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.35f, 0.27f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.32f, 0.34f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.35f, 0.27f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.37f, 0.32f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.37f, 0.32f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.44f, 0.27f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.44f, 0.31f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.44f, 0.31f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.5f, 0.25f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.48f, 0.3f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.48f, 0.3f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.54f, 0.22f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.54f, 0.32f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.54f, 0.32f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.64f, 0.3f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.56f, 0.4f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.56f, 0.4f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.64f, 0.43f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.5f, 0.47f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.5f, 0.47f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.6f, 0.55f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.48f, 0.6f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.48f, 0.6f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.63f, 0.61f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.45f, 0.66f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.45f, 0.66f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.53f, 0.76f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.38f, 0.74f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.38f, 0.74f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.5f, 0.82f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.25f, 0.82f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.25f, 0.82f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.34f, 0.93f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.1f, 0.89f, 0.0f, 1.0f, 0.502f, 0.4941f,

		-0.1f, 0.89f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.13f, 0.98f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.04f, 0.88f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.04f, 0.88f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.04f, 0.98f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.14f, 0.88f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.14f, 0.88f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.24f, 0.96f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.24f, 0.83f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.24f, 0.83f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.42f, 0.86f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.33f, 0.78f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.33f, 0.78f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.5f, 0.73f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.38f, 0.7f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.38f, 0.7f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.55f, 0.58f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.4f, 0.57f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.4f, 0.57f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.58f, 0.48f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.45f, 0.5f, 0.0f, 1.0f, 0.502f, 0.4941f,

		0.45f, 0.5f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.5f, 0.41f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.4f, 0.5f, 0.0f, 1.0f, 0.502f, 0.4941f,

		/*
		0.5f, 0.41f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.4f, 0.5f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.38f, 0.54f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.32f, 0.52f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.32f, 0.58f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.22f, 0.54f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.2f, 0.6f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.11f, 0.52f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.07f, 0.6f, 0.0f,  1.0f, 0.502f, 0.4941f,
		0.04f, 0.5f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.09f, 0.55f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.09f, 0.46f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.2f, 0.49f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.2f, 0.43f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.24f, 0.45f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.25f, 0.39f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.28f, 0.43f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.32f, 0.34f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.35f, 0.27f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.37f, 0.32f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.44f, 0.27f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.44f, 0.31f, 0.0f,  1.0f, 0.502f, 0.4941f,
		-0.5f, 0.25f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.48f, 0.3f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.54f, 0.22f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.54f, 0.32f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.64f, 0.3f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.56f, 0.4f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.64f, 0.43f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.5f, 0.47f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.6f, 0.55f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.48f, 0.6f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.63f, 0.61f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.45f, 0.66f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.53f, 0.76f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.38f, 0.74f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.5f, 0.82f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.25f, 0.82f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.34f, 0.93f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.1f, 0.89f, 0.0f, 1.0f, 0.502f, 0.4941f,
		-0.13f, 0.98f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.04f, 0.88f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.04f, 0.98f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.14f, 0.88f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.24f, 0.96f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.24f, 0.83f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.42f, 0.86f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.33f, 0.78f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.5f, 0.73f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.38f, 0.7f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.55f, 0.58f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.4f, 0.57f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.58f, 0.48f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.45f, 0.5f, 0.0f, 1.0f, 0.502f, 0.4941f,
		0.5f, 0.42f, 0.0f, 1.0f, 0.502f, 0.4941f,
		*/
		

	};

	MeshColor* sukunaColor = new MeshColor();
	sukunaColor->CreateMeshColor(sukunaColorVertices, sizeof(sukunaColorVertices) / sizeof(float));
	meshColorList.push_back(sukunaColor);
}

void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShaderPersonaje, fShaderPersonaje);
	shaderList.push_back(*shader1);
}

int main()
{
	mainWindow = Window(512, 512);
	mainWindow.Initialise();
	CrearFiguras(); //usa MeshColor, �ndices en MeshColorList
	CreateShaders();
	
	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0667f, 0.2157f, 0.1961f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
						
		//Para las letras hay que usar el segundo set de shaders con �ndice 1 en ShaderList 
		shaderList[0].useShader();

		meshColorList[2]->RenderMeshColor();

		glUseProgram(0);
		mainWindow.swapBuffers();

	}
	return 0;
}
