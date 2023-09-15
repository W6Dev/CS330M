#include <application.h>
#include <iostream>


Application::Application(std::string WindowTitle, int width, int height) : _applicationName(WindowTitle), _width(width), _height(height){}


void Application::Run()
{
	// open a window
	if (!openWindow())
	{
		return;
	};

	_running = true;

	// run application
	while (_running)
	{
		if (glfwWindowShouldClose(_window))
		{
			_running = false;
			break;
		}
		glfwSwapBuffers(_window);
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glfwTerminate();
}

bool Application::openWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(800, 600, "CS330 Matt Sandoval", nullptr, nullptr);

	if (!_window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		
	}
	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height)
	{
		// Resize the viewport when the window is resized
		glViewport(0, 0, width, height);
	});


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	
}
