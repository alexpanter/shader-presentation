#include "windows.hpp"
#include "shaders.hpp"
#include "fileIO.hpp"
#include "system.hpp"


void key_callback(GLFWwindow* win, int key, int scancode, int action, int mode)
{
    if(action == GLFW_PRESS && key == GLFW_KEY_ESCAPE)
    {
        glfwSetWindowShouldClose(win, GL_TRUE);
    }
}

int main()
{
    Windows::WindowedWindow window("Example 2", 800, Windows::ASPECT_RATIO_4_3);
    window.SetKeyCallback(key_callback);

    Shaders::ShaderWrapper shader("shader2", Shaders::SHADERS_VF);
    shader.Activate();

    GLuint VBO, VAO;
    GLfloat vertexData[] = {
        // vertexPos   vertexCol
        -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f,   0.0f, 1.0f, 0.0f,
        0.5f, 0.5f,    0.0f, 0.0f, 1.0f
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    // (GLuint index, GLint size, GLenum type, GLboolean normalized,
    //  GLsizei stride, const GLvoid * pointer);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat),
                          (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // texture coordinate
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat),
                          (GLvoid*)(2*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    while(!glfwWindowShouldClose(window.GetWindow()))
    {
        window.PollEvents();
        window.ClearWindow();
        GLfloat time = glfwGetTime();
        shader.SetUniform("xytime", glm::vec2(cos(time), sin(time)));
        glDrawArrays(GL_TRIANGLES, 0, 3);
        window.SwapBuffers();
    }
    window.CloseWindow();

    return 0;
}
