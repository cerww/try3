#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"
class player:public entity
{
    public:
        player();
        virtual ~player();

    protected:

    private:
        //glm::vec4 m_posSize=glm::vec4(0,0,55,55);

};

#endif // PLAYER_H
