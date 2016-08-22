#ifndef HUMAN_H
#define HUMAN_H

//#include <glm/glm.hpp>
#include "entity.h"
class human:public entity
{
    public:
        human(glm::vec2 pos);
        virtual ~human();
        void update();
        //void draw
        static int humans;
    protected:

    private:
        //glm::vec4 m_posSize;
        glm::vec2 m_dir;
        int m_dirLife=0;
        float speed = 1.0f;

};

#endif // HUMAN_H
