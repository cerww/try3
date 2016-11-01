#include "entity.h"

entity::entity(glm::vec4 a,int b):m_posSize(a),m_hp(b)
{
    //ctor
}
entity::entity(glm::vec4 a,int b,GLuint c):m_posSize(a),m_hp(b),m_text(c)
{
    //ctor
}

entity::~entity()
{
    //dtor
}
