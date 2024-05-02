#include<stdio.h>
#include<SDL2/SDL.h>
#include <glad/glad.h>
#include<GLFW/glfw3.h>

/*imena biblioteka za includovanje: 
SDL2 - SDL2/SDL.h
GLFW - GLFW/glfw3.h
image - SDL2p/SDL2_image.h
ttf -SDL2p/SDL2_ttf.h
glad - glad/glad.h
mixer - SDL2p/SDL_mixer.h

VRLO BITNO UVEK PRVO INCLUDUJES GLAD PA ONDA GLFW
*/
const char* vertexShaderSource = "#version 460 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 460 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\0";

int main(int argc, char* argv[])
{
/*so far without the glad, a white window pops up*/
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);/*4.6*/
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

 

    GLFWwindow* window = glfwCreateWindow(800, 800, "MummyMaze", NULL, NULL);
    if (window == NULL) {
        printf("%s", "FAILED");
        return -1;
    }
    glfwMakeContextCurrent(window);

        gladLoadGL();
        glViewport(0, 0, 800, 800);/*coords defined on window*/
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);//rgb,transparency
        glClear(GL_COLOR_BUFFER_BIT);
        //color buffer bit is now the front buffer
        glfwSwapBuffers(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
