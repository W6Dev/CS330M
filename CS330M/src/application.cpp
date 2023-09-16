#include <application.h>
#include <iostream>
#include <types.h>
#include <vector>

Application::Application(std::string WindowTitle, int width, int height) : _applicationName(WindowTitle), _width(width),
                                                                          _height(height) {}

void Application::Run() {
    // open a window
    if (!openWindow()) {
        return;
    };

    _running = true;

    // setup the scene
    setupScene();


    // run application
    while (_running) {
        if (glfwWindowShouldClose(_window)) {
            _running = false;
            break;
        }

        update();
        draw();
    }

    glfwTerminate();
}

bool Application::openWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(800, 600, "CS330 Matt Sandoval", nullptr, nullptr);

    if (!_window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

    }
    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow *window, int width, int height) {
        // Resize the viewport when the window is resized


        glViewport(0, 0, width, height);
    });


    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return false;
    }
    return true;

}

void Application::setupScene() {
    std::vector<Vertex> vertices = {
            {

                    .Position = {-0.5f, 0.5f, 0.0f},
                    .Color = {1.0f, 0.0f, 0.0f}

            },
            {
                    .Position = {-0.5f, -0.5f, 0.0f},
                    .Color = {0.0f, 1.0f, 0.0f}
            },
            {
                    .Position = {0.5f, -0.5f, 0.0f},
                    .Color = {0.0f, 0.0f, 1.0f}
            },
            {
                    .Position = {0.5f, 0.5f, 0.0f},
                    .Color = {1.0f, 0.0f, 0.0f}
            }


    };

    std::vector<uint32_t> elements = {
            0, 1, 2,
            0, 2, 3
    };

    _meshes.emplace_back(std::move(vertices), std::move(elements));

    vertices.clear();
    elements.clear();
}


bool Application::update() {

    return false;
}

bool Application::draw() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for(auto mesh : _meshes)
    {
        mesh.Draw();
    }

    glfwSwapBuffers(_window);
    glfwPollEvents();

    return false;
}




