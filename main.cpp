#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <GL/glx.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <iostream>
#include <string>
#include "sprite.h"
#include "GLSLthingy.h"
#include <memory>
//#include "Picoong.cpp"

GLfloat tocoords(const int &pixels){
return (2.0*pixels/640.0)-1.0;
}
int topixels(const GLfloat &coords){
return (coords+1.0)*320.0;
}
int main(int argc,char ** argv)
{
    //std::cout<<glewGetString(GLEW_VERSION)<<std::endl;


    /* Initialize the library */
    if (!glfwInit())
        return -1;
    GLFWwindow* window;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    //GLenum error =glewInit();

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    GLfloat vert[]={
        0.0,0.0,0.0,
        0.0,0.0,0.0,
        0.0,0.0,0.0,
        0.0,0.0,0.0

    };//0.5,-0.5,0.0
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glewExperimental = GL_TRUE;
    if(glewInit()!=GLEW_OK){
        std::cout<<"a"<<std::endl;
        return -1;
    }/*
    GLuint VBO =0;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vert),vert,GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    //glfwWindowHint();
    /* Loop until the user closes the window */
    int clicks = 0;
    sprite sp(-0.5,0.5,0.5,-0.5,(0<<24)+(255<<16)+(0<<8)+255);

    GLSLthingy colour;
    colour.compileshad("shaderthingy.vert","shaderthingu.frag");
    colour.addAttribute("vertexPos");
    colour.linkshader();/* */
    double xpos, ypos;
    //glfwSwapInterval(1);
    while (!glfwWindowShouldClose(window)){

        //glClearColor(0.0,0.0,1.0,1.0);
        /* Render here *//*

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3,GL_FLOAT,0,vert);
        glDrawArrays(GL_QUADS,0,4);
        glDisableClientState(GL_VERTEX_ARRAY);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        /* Poll for and process events */
        glfwPollEvents();
        glfwGetCursorPos(window, &xpos, &ypos);
        //colour.use();
        sp.draw();
        //colour.unuse();
        //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        if(glfwGetKey(window,GLFW_KEY_RIGHT)) sp.movex(1.0/640.0);
        if(glfwGetKey(window,GLFW_KEY_UP)) sp.movey(1.0/640.0);
        if(glfwGetKey(window,GLFW_KEY_LEFT)) sp.movex(-1.0/640.0);
        if(glfwGetKey(window,GLFW_KEY_DOWN)) sp.movey(-1.0/640.0);

        if(sp.getx()+sp.getheight()>1.0) sp.setx(-1.0);
        if(sp.gety()>1.0) sp.sety(-1.0);
        if(sp.getx()<-1.0) sp.setx(1.0);
        if(sp.gety()<-1.0) sp.sety(1.0);
        //std::cout<<xpos<<" "<<ypos<<std::endl;
        //std::cout<<test<<std::endl;

    }

    glfwTerminate();
    return 0;
}
