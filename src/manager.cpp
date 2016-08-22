#include "manager.h"
#include <GL/glew.h>
//#include <glm/glm.hpp>
manager::manager()
{
    //ctor
}
GLuint manager::currentTextId=0;
GLuint manager::maxFps=60;
camera2D manager::currentCamera={};
manager::~manager()
{
    //dtor
}
