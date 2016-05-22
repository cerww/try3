#include "sprite.h"

sprite::sprite(const GLfloat &x,const GLfloat &y,const GLfloat &l,const GLfloat &h,const GLuint &C):
    time(0.0f),
    x_coord(x),
    y_coord(y),
    length(l),
    height(h),
    color(C)
{
_vboID = 0;
init();
shader.compileshad("shaderthingy.vert","shaderthingu.frag");
shader.addAttribute("vertexPos");
shader.addAttribute("vertexColor");
shader.linkshader();
timeLocation = shader.getUniformLocate("time");
}
void sprite::init(){
if(!_vboID) glGenBuffers(1,&_vboID);
Vertex vertData[6];
//vertData[6];

vertData[0].pos.x = x_coord+length;
vertData[0].pos.y = y_coord;;

vertData[1].pos.x=x_coord;
vertData[1].pos.y=y_coord+height;

vertData[2].pos.x=x_coord;
vertData[2].pos.y=y_coord;
// triangle #2
vertData[3].pos.x=x_coord+length;
vertData[3].pos.y=y_coord;

vertData[4].pos.x=x_coord;
vertData[4].pos.y=y_coord+height;

vertData[5].pos.x=x_coord+length;
vertData[5].pos.y=y_coord+height;

for(GLint i =0; i<6;++i){

    vertData[i].color.r = color>>24;
    vertData[i].color.g = (color>>16)%256;
    vertData[i].color.b = (color>>8)%256;
    vertData[i].color.a = color%256;
        /*
    vertData[i].color.r=0;
    vertData[i].color.b=222;
    vertData[i].color.g=222;
    vertData[i].color.a=255;*/

}

glBindBuffer(GL_ARRAY_BUFFER,_vboID);
glBufferData(GL_ARRAY_BUFFER,sizeof(vertData),vertData,GL_DYNAMIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER,0);

}
sprite::~sprite()
{
    if(_vboID) glDeleteBuffers(1,&_vboID);
}
GLfloat sprite::getx(){
return x_coord;
}
GLfloat sprite::gety(){
return y_coord;
}
void sprite::setx(const GLfloat& x){
x_coord = x;
}
void sprite::sety(const GLfloat& y){
y_coord = y;
}
GLfloat sprite::getheight(){
    return height;
}
GLfloat sprite::getlength(){
    return length;
}
void sprite::movex(const GLfloat &m){
x_coord+=m;
init();
}
void sprite::movey(const GLfloat &m){
y_coord+=m;
init();
}

void sprite::draw(){
time+=0.0005f;

//std::cout<<time<<std::endl;
shader.use();
glUniform1f(timeLocation,time);
glBindBuffer(GL_ARRAY_BUFFER,_vboID);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),offsetof(Vertex,pos));
//glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,0);
glVertexAttribPointer(1,4,GL_UNSIGNED_BYTE,GL_TRUE,sizeof(Vertex),(void*)offsetof(Vertex,color));
glDrawArrays(GL_TRIANGLES,0,6);
glDisableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER,0);
shader.unuse();
}

