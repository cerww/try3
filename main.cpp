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

    double xpos, ypos;
    //glfwSwapInterval(1);
    texture t;
    app a(window);
    t = imgLoader::loadPNG("Enemy_Broccoli1.png");
    GLSLthingy picthingy;
    picthingy.compileshad("texture.vert","texture.frag");
    picthingy.addAttribute("vertPosition");
    picthingy.addAttribute("vertColor");
    picthingy.addAttribute("vertUV");
    picthingy.linkshader();
    pic aPic(0,0.0,0.7,0.8,&t,&picthingy);
    //sprite sp(0.5,0.5,0.5,-0.5,(50<<24)+(255<<16)+(40<<8)+255);
    //sprite sp2(-0.5,0.5,0.5,-0.5,(50<<24)+(255<<16)+(40<<8)+255);
    while (!glfwWindowShouldClose(window)){

        //glClearColor(0.0,0.0,1.0,1.0);
        /* Render here *//*

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3,GL_FLOAT,0,vert);
        glDrawArrays(GL_QUADS,0,4);
        glDisableClientState(GL_VERTEX_ARRAY);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0,1.0,1.0,1.0);
        /* Poll for and process events */
        glfwPollEvents();
        a.update();
        glfwGetCursorPos(window, &xpos, &ypos);
        //glfwSetCursorPos(window,400,400);
        //colour.use();
        //sp.draw();

        aPic.draw();
        //colour.unuse();
        //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        //std::cout<<a.getMouseButton("left")<<std::endl;
        if(a.getMouseButton("left")%200==199) std::cout<<(a.getMouseX()*2.0/640.0)-1<<std::endl;
        if(a.getMouseButton("right")) std::cout<<-1*(a.getMouseY()*2.0/640.0)+1<<std::endl;
        //if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS//){
        //   &&PointinBox(xpos,ypos,topixels(sp.getx()),topixels(-1.0*sp.gety()),topixels(sp.getlength()-1),topixels(-1.0*(sp.getheight()+1)))){
        //if(PointinBox(50,50,0,0,600,600)){
            //std::cout<<"abc"<<std::endl;
            //std::cout<<xpos<<":"<<ypos<<std::endl;
            //std::cout<<sp.getheight()<<std::endl;
            //std::cout<<topixels(sp.getx())<<":"<<topixels(-1.0*sp.gety())<<":"<<topixels(-1.0*(sp.getheight()+1.0))<<":"<<topixels(sp.getlength()-1.0)<<std::endl;

        //std::cout<<xpos<<" "<<ypos<<std::endl;
        //std::cout<<test<<std::endl;
        //std::sleep(.001);
    }
    glfwTerminate();
    //delete window;
    return 0;
}


