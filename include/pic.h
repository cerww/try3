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
#include <memory>
#include "manager.h"
class pic
{
    public:
        pic(const GLfloat &x,const GLfloat &y,const GLfloat &l,const GLfloat &h, texture , std::shared_ptr<GLSLthingy>);
        //pic(const GLint &x,const GLint &y,const GLint &l,const GLint &h, texture , std::shared_ptr<GLSLthingy>);
        virtual ~pic();
        virtual void init();
        virtual void draw();
        //virtual void shaderthinga();
        GLfloat getx() const;
        GLint getxp() const;
        GLint getyp() const;
        GLfloat gety() const;
        GLfloat getheight() const;
        GLint getheightp() const;
        GLint getlengthp() const;
        GLfloat getlength() const;
        void setx(const GLfloat&);
        void setx(const GLint&);
        void sety(const GLint&);
        void sety(const GLfloat&);
        void movex(const GLfloat &m);
        void movex(const GLint &m);
        void movey(const GLint &m);
        void movey(const GLfloat &m);
        texture getTexture();
        GLSLthingy* getShader();
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
        std::shared_ptr<GLSLthingy> _shader;
        GLuint color;
        GLint _x;
        GLint _y;
        GLint _l;
        GLint _h;
        texture _tex;
};

#endif // PIC_Haa
