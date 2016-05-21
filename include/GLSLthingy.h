#ifndef GLSLTHINGY_H
#define GLSLTHINGY_H
#include <string>
#include <iostream>
#include <cstring>
#include <GL/glew.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <GLFW/glfw3.h>
typedef unsigned int uint;
class GLSLthingy
{
    public:
        GLSLthingy();
        virtual ~GLSLthingy();
        void compileshad(const std::string &vertfile,const std::string &fragfile);
        void linkshader();
        void addAttribute(const std::string& attribName);
        GLint getUniformLocate(const std::string& uniName);
        void use();
        void unuse();
    protected:

    private:

        void compleshady(const std::string &filepath,GLuint &ID);
        GLuint programID;
        GLuint vertShadID;
        GLuint fragShadID;
        GLint numAttribs;
};


#endif // GLSLTHINGY_H

