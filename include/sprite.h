#ifndef SPRITE_H
#define SPRITE_H
//#include "Picoong.cpp"
#include <string>
#include <GL/glew.h>
#include <cstdlib>
#include "GLSLthingy.h"
#include "vertex.h"
#include <cstddef>
//
typedef unsigned int uint;
class sprite
{
    public:
        sprite(const GLfloat &x,const GLfloat &y,const GLfloat &l,const GLfloat &h,const GLuint &C);
        GLfloat getx() const;
        GLfloat gety() const;
        GLfloat getheight() const;
        GLfloat getlength() const;
        void setx(const GLfloat&);
        void sety(const GLfloat&);
        virtual void draw();
        virtual ~sprite();
        virtual void init();
        void movex(const GLfloat &m);
        void movey(const GLfloat &m);
        void shaderthinga();
    protected:

    private:
        //GLuint timeLocation;
        //GLfloat time;
        GLfloat x_coord;
        GLfloat y_coord;
        GLfloat length;
        GLfloat height;
        //GLuint corner_coords[4][2];
        GLuint _vboID;
        GLSLthingy shader;
        GLuint color;

};

#endif // SPRITE_H

