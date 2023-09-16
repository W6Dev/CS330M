#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <mesh.h>


class Application
{
public:
	Application(std::string WindowTitle, int width, int height);
	void Run();

private:
	bool openWindow();
    bool draw();
    bool update();

    void setupScene();

private:
	std::string _applicationName{};
	int _width{};
	int _height{};
	GLFWwindow* _window{nullptr};
    GLuint _vertexBufferObject{};
    GLuint _shaderProgram{};
    GLuint _vertexArrayObject{};
    GLuint _elementBufferObject{};

    std::vector<Mesh> _meshes;


	bool _running{false};
};