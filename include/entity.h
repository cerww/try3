#ifndef ENTITY_H
#define ENTITY_H
#include <glm/glm.hpp>

class entity
{
    public:
        entity(glm::vec4);
        virtual ~entity();
        virtual void move(glm::vec2 a){m_posSize+=glm::vec4(a.x,a.y,0,0);};
        virtual glm::vec4 getPosAndSize(){return m_posSize;};
    protected:

    private:
        glm::vec4 m_posSize;
};

#endif // ENTITY_H
