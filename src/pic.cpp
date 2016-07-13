#include "pic.h"

pic::pic(const GLfloat &x,const GLfloat &y,const GLfloat &l,const GLfloat &h,const texture &tex):
    x_coord(x),
    y_coord(y),
    length(l),
    height(h),
    color(0),
    _tex(tex)
{
    //ctor
    init();
    shaderthinga();
}
void pic::shaderthinga(){
shader.compileshad("texture.vert","texture.frag");
shader.addAttribute("vertexPosition");
shader.addAttribute("vertexColor");
shader.addAttribute("vertUV");
shader.linkshader();
}
void pic::init(){
if(!_vboID) glGenBuffers(1,&_vboID);
Vertex vertData[6];
//vertData[6];


vertData[0].setPosition(x_coord+length,y_coord);
vertData[0].setUV(1.0f,0.0f);
vertData[1].setPosition(x_coord,y_coord+height);
vertData[1].setUV(0.0f,1.0f);
vertData[2].setPosition(x_coord,y_coord);
vertData[2].setUV(0.0f,0.0f);
// triangle #2
vertData[3].setPosition(x_coord+length,y_coord);
vertData[3].setUV(1.0f,0.0f);
vertData[4].setPosition(x_coord,y_coord+height);
vertData[4].setUV(0.0f,1.0f);
vertData[5].setPosition(x_coord+length,y_coord+height);
vertData[5].setUV(1.0f,1.0f);
/*
    vertData[0].setPosition(x_coord + length, y_coord + height);
    vertData[0].setUV(1.0f, 1.0f);

    vertData[1].setPosition(x_coord, y_coord + height);
    vertData[1].setUV(0.0f, 1.0f);

    vertData[2].setPosition(x_coord, y_coord);
    vertData[2].setUV(0.0f, 0.0f);

    //Second Triangle
    vertData[3].setPosition(x_coord, y_coord);
    vertData[3].setUV(0.0f, 0.0f);

    vertData[4].setPosition(x_coord + length, y_coord);
    vertData[4].setUV(1.0f, 0.0f);

    vertData[5].setPosition(x_coord + length, y_coord + height);
    vertData[5].setUV(1.0f, 1.0f);*/
glBindBuffer(GL_ARRAY_BUFFER,_vboID);
glBufferData(GL_ARRAY_BUFFER,sizeof(vertData),vertData,GL_DYNAMIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER,0);
std::cout<<(int)vertData[0].color.r<<std::endl;
std::cout<<(int)vertData[0].color.g<<std::endl;
std::cout<<(int)vertData[0].color.b<<std::endl;
std::cout<<(int)vertData[0].color.a<<std::endl;
}
pic::~pic()
{
    //l0a
}
void pic::draw(){

    shader.use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,_tex.id);
    GLint textlocate=shader.getUniformLocate("Text");
    glUniform1i(textlocate,0);

    glBindBuffer(GL_ARRAY_BUFFER,_vboID);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,pos));
    glVertexAttribPointer(1,4,GL_UNSIGNED_BYTE,GL_TRUE,sizeof(Vertex),(void*)offsetof(Vertex,color));
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,uv));
    glDrawArrays(GL_TRIANGLES,0,6);
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);

    glBindTexture(GL_TEXTURE_2D,0);
    shader.unuse();
}
GLfloat pic::getx()const{
return x_coord;
}
GLfloat pic::gety()const{
return y_coord;
}
void pic::setx(const GLfloat& x){
x_coord = x;
}
void pic::sety(const GLfloat& y){
y_coord = y;
}
GLfloat pic::getheight()const{
    return height;
}
GLfloat pic::getlength()const{
    return length;
}
void pic::movex(const GLfloat &m){
x_coord+=m;
init();
}
void pic::movey(const GLfloat &m){
y_coord+=m;
init();
}
