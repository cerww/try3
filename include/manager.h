#ifndef MANAGER_H
#define MANAGER_H
#include <GL/glew.h>

class manager
{
    public:
        manager();
        virtual ~manager();
        static GLuint currentTextId;
        static GLuint windowHeight;// *-1
        static GLuint windowWidth;
        static GLuint maxFps;
    protected:

    private:
};

#endif // MANAGER_H
