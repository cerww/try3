#include "projectile.h"

projectile::projectile(glm::vec2 pos,glm::vec2 dir,const float& speed,const int&life):_position(pos),_direction(dir),_speed(speed),_life(life)
{
    //ctor
}
void projectile::update(){
_position+=(_direction*_speed);
--_life;
if(!_life){

}
}
projectile::~projectile()
{
    //dtor
}
