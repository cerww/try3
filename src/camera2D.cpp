#include "camera2D.h"

camera2D::camera2D():
    _screenWidth(500),
    _screenHeight(500),
    _matUpdate(1),
    _scale(1.0f),
    _pos(0.0f,0.0f),
    _camMatrix(1.0f),
    _orthoMat(1.0f)
{
    //ctor
}
void camera2D::init(const int&screenWidth,const int&screenHeight){
    _screenWidth=screenWidth;
    _screenHeight=screenHeight;
    _orthoMat = glm::ortho(0.0f,(float)_screenWidth,0.0f,(float)_screenHeight);
}
void camera2D::update(){
    if(_matUpdate){
        //glm::mat4 orthoMat = glm::ortho(0.0f,(float)_screenWidth,0.0f,(float)_screenHeight);

        glm::vec3 translate(-_pos.x,-_pos.y+_screenHeight,0.0f);
        _camMatrix = glm::translate(_orthoMat,translate);

        glm::vec3 scale(_scale,_scale,0.0f);
        _camMatrix = glm::scale(glm::mat4(1.0f),scale)*_camMatrix;

        _matUpdate=false;
    }
}
camera2D::~camera2D()
{
    //dtor
}
