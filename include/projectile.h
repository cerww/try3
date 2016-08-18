#ifndef PROJECTILE_H
#define PROJECTILE_H


class projectile
{
    public:
        projectile(glm::vec2,glm::vec2,const float&,const int&);
        virtual ~projectile();
        void update();
    protected:

    private:
        glm::vec2 _position;
        glm::vec2 _direction;
        float _speed;
        int _life;
};

#endif // PROJECTILE_H
