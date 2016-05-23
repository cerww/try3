#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
class texture
{
    public:
        texture();
        virtual ~texture();
        GLuint id;
        int width;
        int height;
    protected:

    private:

};

#endif // TEXTURE_H
