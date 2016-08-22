#include "human.h"
int human::humans=0;
human::human(glm::vec2 pos)://m_posSize(pos,50,50)
    entity(glm::vec4(pos,50,50))
{
    ++humans;
}

void human::update(){
    //m_posSize+=glm::vec4(m_dir.x,m_dir.y,0,0)*speed;
    move(glm::vec2(m_dir.x,m_dir.y)*speed);
    if(m_dirLife--){
        m_dirLife=20;
        //m_dir = vec2();
    }

}
human::~human()
{
    //dtor
    --humans;
}
