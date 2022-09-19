#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}


int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(500, 500, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);


        //  1. glm에 있는 sin 과 cos 함수를 활용하여 OpenGL의 line strip으로 화면에 해당하는 2차원 공간상에서 반지름이 1인 원을 그려보도록 하자.    

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0f, 0.0f, 1.0f);
        double rd = 1;
        glBegin(GL_LINE_STRIP);
        //360도 돌리고돌리고
        for (int i = 0; i < 360; i++)
        {   
            float angle, x, y;
            angle = i * 3.14 / 180;

            //각도랑 반지름 
            x = rd * cos(angle);
            y = rd * sin(angle);

            //그려주고
            glVertex2f(x, y);
        }
        
        glEnd();
        glFinish();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
