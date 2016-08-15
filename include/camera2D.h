#ifndef CAMERA2D_H
#define CAMERA2D_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class camera2D
{
    public:
        camera2D();
        virtual ~camera2D();
        void update();
        void init(const int&,const int&);
        //setter
        void setPos(glm::vec2 newPos){_pos = newPos;_matUpdate=true;}
        void setScale(const float& newScale){_scale = newScale;_matUpdate=true;}
        //getter
        glm::vec2 getPos(){return _pos;}
        float getScale(){return _scale;}
        glm::mat4 getCamMatrix(){return _camMatrix;}
    protected:

    private:
        int _screenWidth;
        int _screenHeight;
        bool _matUpdate;
        float _scale;
        glm::vec2 _pos;
        glm::mat4 _camMatrix;
        glm::mat4 _orthoMat;
};

#endif // CAMERA2D_H
