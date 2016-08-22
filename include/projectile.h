#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <glm/glm.hpp>
#include "SpriteBatch.h"
#include <GL/glew.h>
#include <iostream>
class projectile
{
    public:
        projectile(glm::vec2,glm::vec2,const float&,const int&,GLuint);
        virtual ~projectile();
        bool update();
        void draw(SpriteBatch& spriteBatch);
        void die();
        glm::vec4 getPosAndSize(){return glm::vec4(_position.x, _position.y, 15, 15);};
        GLuint getText(){return _textID;};
    protected:

    private:
        glm::vec2 _position;
        glm::vec2 _direction;
        float _speed;
        int _life;
        GLuint _textID;
};

#endif // PROJECTILE_H
