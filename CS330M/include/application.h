#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>



class Application
{
public:
	Application(std::string WindowTitle, int width, int height);
	void Run();

private:
	bool openWindow();

private:
	std::string _applicationName{};
	int _width{};
	int _height{};
	GLFWwindow* _window{nullptr};
	bool _running{false};
};