#include "imgLoader.h"
#include "picopng.h"
#include "IOmanager.h"
#include "stdio.h"
#include <GLFW/glfw3.h>
imgLoader::imgLoader()
{
    //ctor
}
texture imgLoader::loadPNG(const std::string &path){
    texture tex={};
    std::vector<unsigned char> in;
    std::vector<unsigned char> outpic;
    unsigned long width,height;
    //asd();
    if(!IOmanager::readFileToBuffer(path,in)){
    //if(!IOmanager::readFileToBuffer(path,in)){
        printf("4\n");
        glfwTerminate();
    }
    int error = decodePNG(outpic,width,height,&in[0],in.size());
    if(!error){
        printf("decodePNG failed with %d",error);
    }
    glGenTextures(1,&tex.id);
    glBindTexture(GL_TEXTURE_2D,tex.id);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,&outpic[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    tex.width =width;
    tex.height = height;
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,0);
    return tex;
}
imgLoader::~imgLoader()
{
    //dtor
}
