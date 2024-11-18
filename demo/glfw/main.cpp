#include <cassert>

#include <spdlog/spdlog.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

void err_cllbck(int err, const char* desc) {
    spdlog::error("[{}]: {}", err, desc);
}

int main(int argc, char** argv) {
    if(!glfwInit()) {
        spdlog::error("Failed to initalize glfw");
        return 1;
    }
    glfwSetErrorCallback(err_cllbck);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* win = glfwCreateWindow(800, 600, "UUIF - demo", nullptr, nullptr);
    assert(win != nullptr && "Failed to crate window");

    glfwMakeContextCurrent(win);
    // gladLoadGL(glfwGetProcAddress);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);


    glfwDestroyWindow(win);
    glfwTerminate();
}
