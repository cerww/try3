#ifndef BLOCK_H
#define BLOCK_H
#include "entity.h"
#include <GL/glew.h>
class block:public entity
{
    public:
        block(float,float,int,GLuint);
        virtual ~block();
    protected:

    private:
        GLuint m_text;
        //GLuint m_hp;
};

#endif // BLOCK_H
