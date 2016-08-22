#include "projectile.h"

projectile::projectile(glm::vec2 pos,glm::vec2 dir,const float& speed,const int&life,GLuint ID):
    _position(pos),_direction(dir),_speed(speed),_life(life),_textID(ID)
{
    //ctor
}
bool projectile::update(){
    //std::cout<<_position.x<<" "<<_position.y<<std::endl;
    _position+=(_direction*_speed);
    if(!--_life){
        return true;
    }return false;
}
void projectile::die(){
    _life = 0;
}
void projectile::draw(SpriteBatch& spriteBatch){
    glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);

    Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;

    glm::vec4 posAndSize = glm::vec4(_position.x, _position.y, 30, 30);

    spriteBatch.draw(posAndSize, uv, _textID,color, 0.0f);
}
projectile::~projectile()
{
    //dtor
}
