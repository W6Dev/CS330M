
add_subdirectory(external/cmakelibs/glfw)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE GLAD_SOURCES external/shared/glad/*.c)


add_executable(${PROJECT_NAME} ${SOURCES} ${GLAD_SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
            include/
            external/shared/glad/include/
            glfw
        )
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        PRIVATE
            glfw
            OpenGL::GL
        )