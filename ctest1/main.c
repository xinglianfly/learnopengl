//GLEW
#include <OpenGL/gl3.h>

// GLFW

#include <GLFW/glfw3.h>
#include <stdio.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // 当用户按下ESC键,我们设置window窗口的WindowShouldClose属性为true
    // 关闭应用程序
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
    glfwInit();//初始化glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);//os系统需要加上这句话我们的配置才会生效
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "learn", NULL, NULL);
    if (window == NULL) {
        printf( "failed to create GLFW window" );
        glfwTerminate();
        return -1;
        
    }
    int width=800;
    int height = 600;
    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
   
    
    while (!glfwWindowShouldClose(window) ) {//每一次循环开始前检查一次GLFW是否准备好要退出，如果这样的话，返回true然后游戏循环就结束了
        glfwPollEvents();//有没有触发什么事件，然后调用对应的回调函数，
        //下面是执行各种渲染工作
        glfwSetKeyCallback(window, key_callback);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);//交换缓冲区（储存着GLFW窗口每一个像素颜色的缓冲区）
    }
    
   
    
    glfwTerminate();
    
    return 0;
}


