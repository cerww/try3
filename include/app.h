#pragma once
#ifndef APP_H
#define APP_H
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <string>
#include "texture.h"
#include "GLSLthingy.h"
#include "imgLoader.h"
#include "pic.h"
#include "SpriteBatch.h"
#include "manager.h"
#include "camera2D.h"
#include "fpslimiter.h"
#include <thread>
#include <future>
struct keys{
std::unordered_map<std::string,int> k;
std::unordered_map<std::string,int> m;
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
        texture getTexture(const std::string&);
        //void addTexture(const std::string&,const std::string&);
        std::shared_ptr<GLSLthingy> getShader(const std::string&);
        void addShader(const std::string&,const std::string&,const std::string&,const std::vector<std::string>&);
        void addSprite(const std::string&,const std::shared_ptr<pic>&);
        bool removeSprite(const std::string&);
        void setMaxFPS(const int&);
        camera2D camera;
    protected:

    private:
        void test();
        GLFWwindow* _window;
        keys _keys;
        double _ypos;
        double _xpos;
        std::map<std::string,texture> _textures;
        std::map<std::string,std::shared_ptr<GLSLthingy>> _GLSLstuffs;
        std::vector<std::shared_ptr<pic>> _imgs;
        SpriteBatch _spriteBatch;
        int _maxFPS;
        //double currentFrame=0;
        //double _prevFrame = glfwGetTime();
        fpslimiter _fpsLimiter;
        void updateKeys();
};

#endif // APP_H
