#ifndef PIC_H
#define PIC_H
#include "sprite.h"
#include <string>
#include <GL/glew.h>
#include <cstdlib>
#include "GLSLthingy.h"
#include "vertex.h"
#include <cstddef>
#include "texture.h"
class pic
{
    public:
        pic(const GLfloat &x,const GLfloat &y,const GLfloat &l,const GLfloat &h,const texture &);
        virtual ~pic();
        virtual void init();
        virtual void draw();
        virtual void shaderthinga();
        GLfloat getx() const;
        GLfloat gety() const;
        GLfloat getheight() const;
        GLfloat getlength() const;
        void setx(const GLfloat&);
        void sety(const GLfloat&);
        void movex(const GLfloat &m);
        void movey(const GLfloat &m);
    protected:

    private:
        //std::string _url;
        //texture _tex
        GLfloat x_coord;
        GLfloat y_coord;
        GLfloat length;
        GLfloat height;
        //GLuint corner_coords[4][2];
        GLuint _vboID;
        GLSLthingy shader;
        GLuint color;
        GLint _x;
        GLint _y;
        GLint _l;
        GLint _w;
        texture _tex;
};

#endif // PIC_Haa
