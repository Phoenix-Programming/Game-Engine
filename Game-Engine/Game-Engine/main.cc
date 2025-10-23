#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

int main()
{
	std::cout << "Hello world!\n";

	if (!glfwInit())
	{
		std::cout << "Error Initializing GLFW!\n";
		return 0;
	}

	glfwTerminate();

	return 0;
}