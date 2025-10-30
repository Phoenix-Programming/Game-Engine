#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#pragma region Should Be Migrated To Another File

GLFWwindow* window;
int defaultScreenWidth = 800, defaultScreenHeight = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

bool InitGLFW()
{
	if (!glfwInit())
	{
		std::cout << "Error Initializing GLFW!\n";
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(defaultScreenWidth, defaultScreenHeight, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return true;
}

void DeInitGLFW()
{
	glfwTerminate();
}

bool InitGLAD()
{
	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return true;
	
	std::cout << "Error Initializing GLAD\n";
	return false;
}

#pragma endregion

int main()
{
	std::cout << "Hello world!\n";

	InitGLFW();
	InitGLAD();

	// Game here
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.2f, 0.2f, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	DeInitGLFW();
	
	return 0;
}