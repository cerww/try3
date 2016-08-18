#include "pic.h"

pic::pic(const GLfloat &x,const GLfloat &y,const GLfloat &l,const GLfloat &h, texture tex, std::shared_ptr<GLSLthingy> shader):
    x_coord(x),
    y_coord(y),
    length(l),
    height(h),
    color(0),
    _tex(tex),
    _shader(shader)
{
    init();
}
/*
pic::pic(const GLint &x,const GLint &y,const GLint &l,const GLint &h, texture tex, std::shared_ptr<GLSLthingy>shader):
x_coord((x*2.0f/manager::windowWidth)-1.0f),
y_coord(-1.0f*((y*2.0f/manager::windowHeight)-1.0f)),
length(2.0f*l/manager::windowWidth),
height(-2.0f*h/manager::windowHeight),
_shader(shader),
color(0),
_x(x),
_y(y),
_l(l),
_h(h),
_tex(tex){
init();

}*/
/*
void pic::shaderthinga(){
shader.compileshad("texture.vert","texture.frag");
shader.addAttribute("vertPosition");
shader.addAttribute("vertColor");
shader.addAttribute("vertUV");
shader.linkshader();
}*/
void pic::init(){
if(!_vboID) glGenBuffers(1,&_vboID);
Vertex vertData[6];
//vertData[6];

/*
vertData[0].setPosition(x_coord+length,y_coord);
vertData[0].setUV(1.0f,0.0f);
//vertData[0].setColour(255);
vertData[1].setPosition(x_coord,y_coord+height);
vertData[1].setUV(0.0f,1.0f);
//vertData[1].setColour(255);
vertData[2].setPosition(x_coord,y_coord);
vertData[2].setUV(0.0f,0.0f);
//vertData[2].setColour(255);
// triangle #2
vertData[3].setPosition(x_coord+length,y_coord);
vertData[3].setUV(1.0f,0.0f);
//vertData[3].setColour(255);
vertData[4].setPosition(x_coord,y_coord+height);
vertData[4].setUV(0.0f,1.0f);
//vertData[4].setColour(255);
vertData[5].setPosition(x_coord+length,y_coord+height);
vertData[5].setUV(1.0f,1.0f);
//vertData[5].setColour(255);
*/
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
    vertData[5].setUV(1.0f, 1.0f);
    /* */
glBindBuffer(GL_ARRAY_BUFFER,_vboID);
glBufferData(GL_ARRAY_BUFFER,sizeof(vertData),vertData,GL_DYNAMIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER,0);
}
pic::~pic()
{
    //l0a
}
void pic::draw(){

    //_shader->use();


    glBindBuffer(GL_ARRAY_BUFFER,_vboID);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,pos));
    glVertexAttribPointer(1,4,GL_UNSIGNED_BYTE,GL_TRUE,sizeof(Vertex),(void*)offsetof(Vertex,color));
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,uv));
    glDrawArrays(GL_TRIANGLES,0,6);
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);

    //glBindTexture(GL_TEXTURE_2D,0);
    //_shader->unuse();
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
texture pic::getTexture(){
return _tex;
}
GLSLthingy* pic::getShader(){
return _shader.get();
}
