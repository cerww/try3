#include "block.h"

block::block(float x,float y,int hp,GLuint c):
    entity(glm::vec4(x,y,60,60),hp,c)
{
    //ctor
}

block::~block()
{
    //dtor
}
