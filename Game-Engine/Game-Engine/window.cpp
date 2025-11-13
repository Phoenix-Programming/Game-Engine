#include "window.h"

std::vector<Window*> Window::windows{ };
bool Window::glfwInitialized = false, Window::gladInitialized = false;

Window::Window(int width, int height) :
	width(width), height(height)
{
	if (!glfwInitialized)
		glfwInitialized = InitGLFW();
	if (!gladInitialized)
		gladInitialized = InitGLAD();

	window = glfwCreateWindow(width, height, "Game Engine Project", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	windows.push_back(this);
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::Start()
{
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Window::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(window);

	glClearColor(0.2f, 0.2f, 0.2f, 0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::Close()
{
	glfwDestroyWindow(window);
}

Window& Window::GetWindow(GLFWwindow* glfwWindow)
{
	for (Window* window : Window::windows)
		if (window->window == glfwWindow)
			return *window;
}

void Window::framebuffer_size_callback(GLFWwindow* glfwWindow, int width, int height)
{
	glViewport(0, 0, width, height);
	Window& window = Window::GetWindow(glfwWindow);
	window.width = width;
	window.height = height;
}

bool Window::InitGLFW()
{
	if (!glfwInit())
	{
		std::cout << "Error Initializing GLFW!\n";
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return true;
}

bool Window::InitGLAD()
{
	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return false;

	std::cout << "Error Initializing GLAD\n";
	return true;
}

void Window::DeInitGLFW()
{
	glfwTerminate();
}