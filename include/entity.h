#ifndef ENTITY_H
#define ENTITY_H
#include <glm/glm.hpp>
#include <GL/glew.h>
class entity
{
    public:
        entity(glm::vec4,int);
        entity(glm::vec4,int,GLuint);
        virtual ~entity();
        virtual void move(glm::vec2 a){m_posSize+=glm::vec4(a.x,a.y,0,0);};
        void setPos(glm::vec2 a){m_posSize=glm::vec4(a.x,a.y,m_posSize.z,m_posSize.w);};
        virtual glm::vec4 getPosAndSize(){return m_posSize;};
        virtual glm::vec2 getSize(){return glm::vec2(m_posSize.z,m_posSize.w);};
        virtual glm::vec2 getPos(){return glm::vec2(m_posSize.x,m_posSize.y);};
        GLuint getHP(){return m_hp;};
        void loseHP(const int& a){m_hp-=a;};
        GLuint getText(){return m_text;};
    protected:

    private:
        glm::vec4 m_posSize;
        GLuint m_hp;
        GLuint m_text;
};

#endif // ENTITY_H
