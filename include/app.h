#ifndef APP_H
#define APP_H
#include <map>
#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <string>
#include "texture.h"
#include "GLSLthingy.h"
#include "imgLoader.h"
struct keys{
std::map<std::string,int> k;
std::map<std::string,int> m;
};
class app
{
    public:
        app(GLFWwindow* &);
        app(const app&);
        virtual ~app();
        void update();
        int getKey(const std::string &key) ;
        double getMouseX() const;
        double getMouseY() const;
        int getMouseButton(const std::string &Button);
        texture* getTexture(const std::string&);
        void addTexture(const std::string&,const std::string&);

    protected:

    private:
        GLFWwindow* _window;
        keys _keys;
        double _ypos;
        double _xpos;
        std::map<std::string,texture> _textures;
        std::map<std::string,GLSLthingy> _GLSLstuffs;
};

#endif // APP_H
