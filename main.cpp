#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <GL/glx.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
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
GLfloat tocoords(const int &pixels){
return (2.0*pixels/640.0)-1.0;
}
int topixels(const GLfloat &coords){
return (coords+1.0)*320.0;
}
bool PointinBox(const int &x,const int& y,const int& p1,const int& p2,const int& l,const int& h){
return x>p1&&x<p1+l&&y>p2&&y<p2+h;
}
void dothings(const std::unique_ptr<int> &l){
*l+=1;
}
int rgbColour(const char &r,const char &g,const char &b){
return (r<<24)+(g<<16)+(b<<8)+255;
}
void sleepy(const int&sleeptime){
    time_t timer1=time(nullptr);
    time_t timer2=time(nullptr);
    while(difftime(timer1,timer2)>sleeptime){
        timer2 = time(nullptr);
    }
}
std::string tostring(const int&num){
    std::string returnStr="";
    for(int place = ceil(log10(num+1))-1;place>-1;--place){
        returnStr.push_back(((int)(num/pow(10.0,place))%10)+48);
    }return returnStr;
}
int main(int argc,char ** argv){

    //sleepy(10);
    //usleep(1232189732121898921);
    //Sleep(1000);
    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
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
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    //GLFWwindow* window2;
    //window2= glfwCreateWindow(400,400,"abc",NULL,NULL);
    /*GLuint VBO =0;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vert),vert,GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    //glfwWindowHint();*/
    /* Loop until the user closes the window */
    //sprite sp(-0.5,0.5,0.5,-0.5,(50<<24)+(255<<16)+(40<<8)+255);
    int width, height;
    double xpos, ypos;
    glfwGetFramebufferSize(window, &width, &height);
    manager::windowHeight=height;
    manager::windowWidth=width;
    //glfwSwapInterval(1);
    texture t;
    app a(window);
    t = imgLoader::loadPNG("Enemy_Broccoli1.png");
    //glfwSwapInterval(1);
    //a.addTexture("broccoli1","Enemy_Broccoli1.png");
    a.addShader("pics","texture.vert","texture.frag",{"vertPosition","vertColor","vertUV"});
    //pic aPic(0,0.0,0.7,0.8,a.getTexture("broccoli1"),a.getShader("pics"));
    //auto somepic = std::shared_ptr<pic>(new pic(0.0f,0.0f,0.3f,-0.3f,a.getTexture("Enemy_Broccoli1.png"),a.getShader("pics")));
    //a.addSprite(somepic);
    for(int x=0;x<10;++x){
        a.addSprite("things"+tostring(x),std::shared_ptr<pic>(new pic(0.1f*x,0.1f*x,0.3f,-0.3f,a.getTexture("Enemy_broccoli1.png"),a.getShader("pics"))));
    }

    std::cout<<glfwGetTime()<<std::endl;
    auto abb = std::shared_ptr<pic>(new pic(0,0,200,400,a.getTexture("Enemy_broccoli1.png"),a.getShader("pics")));
    a.addSprite("guy",abb);
    //sprite sp(0.5,0.5,0.5,-0.5,(50<<24)+(255<<16)+(40<<8)+255);
    //sprite sp2(-0.5,0.5,0.5,-0.5,(50<<24)+(255<<16)+(40<<8)+255);
    double currentFrame=0;
    double prevFrame = glfwGetTime();
    while (!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glfwGetFramebufferSize(window, &width, &height);
        manager::windowHeight=height;
        manager::windowWidth=width;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0,1.0,1.0,1.0);
        /* Poll for and process events */
        glfwPollEvents();
        a.update();
        currentFrame=glfwGetTime();
        if(currentFrame-prevFrame<1.0/manager::maxFps){
            std::this_thread::sleep_for(std::chrono::microseconds((int)(1000000.0*((1.0/manager::maxFps)-(currentFrame-prevFrame)))));
        }prevFrame=currentFrame;
        //std::cout<<prevFrame*1000.0f<<std::endl;
        glfwGetCursorPos(window, &xpos, &ypos);
        if(a.getMouseButton("left")%60==59) std::cout<<(a.getMouseX()*2.0/640.0)-1<<std::endl;
        if(a.getMouseButton("right")) std::cout<<-1*(a.getMouseY()*2.0/640.0)+1<<std::endl;
    }
    glfwTerminate();
    //delete window;
    return 0;
}


