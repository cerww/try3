#ifndef IMGLOADER_H
#define IMGLOADER_H
#include "texture.h"
#include <string>
class imgLoader
{
    public:
        imgLoader();
        virtual ~imgLoader();
        static texture loadPNG(const std::string &path);
    protected:

    private:
};

#endif // IMGLOADER_H
