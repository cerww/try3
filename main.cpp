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
#include "player.h"
#include "human.h"
#include "projectile.h"
//#include "vertex.h"
#define STOCK_UV glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)
bool checkCollision(const glm::vec4& first,const glm::vec4& second){
if(first.x+first.z);
}
bool pointInBox(glm::vec2 a,glm::vec4 b){
if(a.x>b.x&&a.x<b.x+b.z&&a.y>b.y&&a.y<b.y+b.w) return true;
return false;
}
int checkCollision(glm::vec4 a,glm::vec4 b){
if(pointInBox(glm::vec2(a.x+a.z,a.y),b))return 1;
if(pointInBox(glm::vec2(a.x,a.y),b))return 2;
if(pointInBox(glm::vec2(a.x,a.y+a.w),b))return 3;
if(pointInBox(glm::vec2(a.x+a.z,a.y+a.w),b))return 4;
//return pointInBox(a.x+a.z,b):1?(pointInBox(a.x,b)):2?(pointInBox(a.y+a.w,b)):3?(pointInBox(a.y,b)):4?0
return 0;
}
template <class T>
void mySwap(T& a,T& b){
    if(&a==&b) return;
    T temp=a;
    a = b;
    b=temp;
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
    Color color;
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

    //glfwSwapInterval(1);
    app a(window);
    glm::vec2 tempMoveVec(0,0);
    a.addShader("pics","texture.vert","texture.frag",{"vertPosition","vertColor","vertUV"});
    auto thePlayer=std::make_shared<player>();
    human human1(glm::vec2(20,20));
    std::vector<projectile> projectileList;
    while (!glfwWindowShouldClose(window)){
        a.updateKeys();
        a.start();
        tempMoveVec=glm::vec2(0,0);
        if(a.getKey("left"))tempMoveVec+=glm::vec2(-4,0);
        if(a.getKey("right"))tempMoveVec+=glm::vec2(4,0);
        if(a.getKey("up"))tempMoveVec+=glm::vec2(0,4);
        if(a.getKey("down"))tempMoveVec+=glm::vec2(0,-4);
        thePlayer->move(tempMoveVec);
        if(a.getMouseButton("left")){
            projectileList.emplace_back(glm::vec2(thePlayer->getPosAndSize().x+25.5,thePlayer->getPosAndSize().y+25.5),
                                        a.camera.screenToWorld(a.getMousePos())-glm::vec2(thePlayer->getPosAndSize().x+25.5,thePlayer->getPosAndSize().y+25.5),
                                        0.02,
                                        200,
                                        a.getTexture("circle.png").id);
            //std::cout<<projectileList.size()<<std::endl;
        }
        if(a.getMouseButton("right"))std::cout<<a.camera.screenToWorld(a.getMousePos()).x<<" "<<a.camera.screenToWorld(a.getMousePos()).y<<std::endl;
        a.camera.setPos(a.camera.getPos()+tempMoveVec);
        //for(auto &x:projectileList){

        for(int x = 0;x<projectileList.size();++x){
            if(projectileList[x].update()){
                mySwap(projectileList[x],projectileList[projectileList.size()-1]);
                projectileList.pop_back();
                continue;
            }
            a.draw(projectileList[x].getPosAndSize(),STOCK_UV,a.getTexture("circle.png").id,Color(0,0,0,255),1.0f);

        }//a.draw(glm::vec4(0,60,30,30),STOCK_UV,a.getTexture("circle.png").id,Color(0,0,0,255),1.0f);

        a.draw(human1.getPosAndSize(),STOCK_UV,a.getTexture("circle.png").id,Color(200,200,200,255),1.0f);
        a.draw(thePlayer->getPosAndSize(),STOCK_UV,a.getTexture("circle.png").id,Color(0,200,200,255),1.0f);
        a.end();
    }
    glfwTerminate();
    return 0;
}


