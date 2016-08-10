#include "manager.h"
#include <GL/glew.h>
manager::manager()
{
    //ctor
}
GLuint manager::currentTextId=0;
GLuint manager::windowHeight;
GLuint manager::windowWidth;
GLuint manager::maxFps=60;
manager::~manager()
{
    //dtor
}
