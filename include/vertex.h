#ifndef VERTEX_H
#define VERTEX_H
#include <GL/glew.h>
struct Position{
        float x;
        float y;
};

struct Color{
        GLubyte r=255;
        GLubyte g=255;
        GLubyte b=255;
        GLubyte a=255;
        };
struct UV{
GLfloat u;
GLfloat v;
};
struct Vertex{
    Position pos;
    Color color;
    UV uv;
    void setColour(const GLuint& colour){
    color.r = colour>>24;
    color.g = (colour>>16)%256;
    color.b = (colour>>8)%256;
    color.a = colour%256;
    }
    void setUV(const GLfloat &u,const GLfloat &v){
    uv.u=u;
    uv.v=v;
    }
    void setPosition(const float &x,const float &y){
    pos.x=x;
    pos.y=y;
    }

};

#endif // VERTEX_H
