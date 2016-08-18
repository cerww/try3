#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgLoader.h"
#include <iostream>
#include <string>
#include "sprite.h"
#include "GLSLthingy.h"
#include <memory>
#include "texture.h"
#include "pic.h"
#include <fstream>
#include "app.h"
#include <ctime>
#include "manager.h"
#include <time.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
#include <glm/glm.hpp>
#include "camera2D.h"
#include "SpriteBatch.h"
int main(int argc,char ** argv){
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    GLFWwindow* window;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
    //window = glfwCreateWindow(1920, 1080, "Hello World", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }
    //GLenum error =glewInit();

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glewExperimental = GL_TRUE;
    if(glewInit()!=GLEW_OK){
        std::cout<<"a"<<std::endl;
        return -1;
    }
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    //glfwSwapInterval(1);
    app a(window);
    a.addShader("pics","texture.vert","texture.frag",{"vertPosition","vertColor","vertUV"});
    while (!glfwWindowShouldClose(window)){
        a.update();
        if(a.getKey("up")) a.camera.setPos(a.camera.getPos()+glm::vec2(0.0f,10.0f));
        if(a.getKey("down")) a.camera.setPos(a.camera.getPos()+glm::vec2(0.0f,-10.0f));
        if(a.getKey("right")) a.camera.setPos(a.camera.getPos()+glm::vec2(10.0f,0.0f));
        if(a.getKey("left")) a.camera.setPos(a.camera.getPos()+glm::vec2(-10.0f,0.0f));
        if(a.getMouseButton("left")%60==1) std::cout<<(a.getMouseX()*2.0/640.0)-1<<std::endl;
        if(a.getMouseButton("right")) std::cout<<-1*(a.getMouseY()*2.0/640.0)+1<<std::endl;
    }
    glfwTerminate();
    return 0;
}


