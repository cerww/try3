#ifndef APP_H
#define APP_H
#include <map>
#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
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
        int getKey(const std::string &key);
        double getMouseX() const;
        double getMouseY() const;
        int getMouseButton(const std::string &Button);
    protected:

    private:
        GLFWwindow* _window;
        keys _keys;
        double _ypos;
        double _xpos;

};

#endif // APP_H
