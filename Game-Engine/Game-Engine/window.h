#ifndef WINDOW_WINDOW_H_
#define WINDOW_WINDOW_H_

#include <vector>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

constexpr int defaultWindowWidth = 800, defaultWindowHeight = 600;

class Window
{
public:
	static std::vector<Window*> windows;
	static bool glfwInitialized, gladInitialized;

	GLFWwindow* window;
	int width, height;

	Window(int width, int height);

	bool ShouldClose();

	void Start();
	void Update();
	void Close();

	static Window& GetWindow(GLFWwindow* window);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static bool InitGLFW();
	static bool InitGLAD();
	static void DeInitGLFW();
};

#endif  // WINDOW_WINDOW_H_