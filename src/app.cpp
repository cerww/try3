#include "app.h"

app::app(GLFWwindow* &window):_window(window),_ypos(0.0f),_xpos(0.0f){
    //keybourd
    _keys.k["a"]=0;
    _keys.k["b"]=0;
    _keys.k["c"]=0;
    _keys.k["d"]=0;
    _keys.k["e"]=0;
    _keys.k["f"]=0;
    _keys.k["g"]=0;
    _keys.k["h"]=0;
    _keys.k["i"]=0;
    _keys.k["j"]=0;
    _keys.k["k"]=0;
    _keys.k["l"]=0;
    _keys.k["m"]=0;
    _keys.k["n"]=0;
    _keys.k["o"]=0;
    _keys.k["p"]=0;
    _keys.k["q"]=0;
    _keys.k["r"]=0;
    _keys.k["s"]=0;
    _keys.k["t"]=0;
    _keys.k["u"]=0;
    _keys.k["v"]=0;
    _keys.k["w"]=0;
    _keys.k["x"]=0;
    _keys.k["y"]=0;
    _keys.k["z"]=0;
    _keys.k["1"]=0;
    _keys.k["2"]=0;
    _keys.k["3"]=0;
    _keys.k["4"]=0;
    _keys.k["5"]=0;
    _keys.k["6"]=0;
    _keys.k["7"]=0;
    _keys.k["8"]=0;
    _keys.k["9"]=0;
    _keys.k["left"]=0;
    _keys.k["right"]=0;
    _keys.k["up"]=0;
    _keys.k["space"]=0;
    _keys.k["down"]=0;
    _keys.k["esc"]=0;
    //mouse
    _keys.m["left"]=0;
    _keys.m["right"]=0;
    _keys.m["middle"]=0;
}
int app::getKey(const std::string &key){
return _keys.k[key];
}
int app::getMouseButton(const std::string &Button){
return _keys.m[Button];
}

double app::getMouseX() const{return _xpos;}
double app::getMouseY() const{return _ypos;}
void app::update(){
//mouse
glfwGetCursorPos(_window,&_xpos,&_ypos);
if(glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT))++_keys.m["left"];else _keys.m["left"]=0;
if(glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_RIGHT))++_keys.m["right"];else _keys.m["right"]=0;
if(glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_MIDDLE))++_keys.m["middle"];else _keys.m["middle"]=0;
//keys
if(glfwGetKey(_window,GLFW_KEY_A)) ++_keys.k["a"]; else _keys.k["a"]=0;
if(glfwGetKey(_window,GLFW_KEY_B)) ++_keys.k["b"]; else _keys.k["b"]=0;
if(glfwGetKey(_window,GLFW_KEY_C)) ++_keys.k["c"]; else _keys.k["c"]=0;
if(glfwGetKey(_window,GLFW_KEY_D)) ++_keys.k["d"]; else _keys.k["d"]=0;
if(glfwGetKey(_window,GLFW_KEY_E)) ++_keys.k["e"]; else _keys.k["e"]=0;
if(glfwGetKey(_window,GLFW_KEY_F)) ++_keys.k["f"]; else _keys.k["f"]=0;
if(glfwGetKey(_window,GLFW_KEY_G)) ++_keys.k["g"]; else _keys.k["g"]=0;
if(glfwGetKey(_window,GLFW_KEY_H)) ++_keys.k["h"]; else _keys.k["h"]=0;
if(glfwGetKey(_window,GLFW_KEY_J)) ++_keys.k["j"]; else _keys.k["j"]=0;
if(glfwGetKey(_window,GLFW_KEY_K)) ++_keys.k["k"]; else _keys.k["k"]=0;
if(glfwGetKey(_window,GLFW_KEY_L)) ++_keys.k["l"]; else _keys.k["l"]=0;
if(glfwGetKey(_window,GLFW_KEY_M)) ++_keys.k["m"]; else _keys.k["m"]=0;
if(glfwGetKey(_window,GLFW_KEY_N)) ++_keys.k["n"]; else _keys.k["n"]=0;
if(glfwGetKey(_window,GLFW_KEY_O)) ++_keys.k["o"]; else _keys.k["o"]=0;
if(glfwGetKey(_window,GLFW_KEY_P)) ++_keys.k["p"]; else _keys.k["p"]=0;
if(glfwGetKey(_window,GLFW_KEY_Q)) ++_keys.k["q"]; else _keys.k["q"]=0;
if(glfwGetKey(_window,GLFW_KEY_R)) ++_keys.k["r"]; else _keys.k["r"]=0;
if(glfwGetKey(_window,GLFW_KEY_S)) ++_keys.k["s"]; else _keys.k["s"]=0;
if(glfwGetKey(_window,GLFW_KEY_T)) ++_keys.k["t"]; else _keys.k["t"]=0;
if(glfwGetKey(_window,GLFW_KEY_U)) ++_keys.k["u"]; else _keys.k["u"]=0;
if(glfwGetKey(_window,GLFW_KEY_V)) ++_keys.k["v"]; else _keys.k["v"]=0;
if(glfwGetKey(_window,GLFW_KEY_W)) ++_keys.k["w"]; else _keys.k["w"]=0;
if(glfwGetKey(_window,GLFW_KEY_X)) ++_keys.k["x"]; else _keys.k["x"]=0;
if(glfwGetKey(_window,GLFW_KEY_Y)) ++_keys.k["y"]; else _keys.k["y"]=0;
if(glfwGetKey(_window,GLFW_KEY_Z)) ++_keys.k["z"]; else _keys.k["z"]=0;
if(glfwGetKey(_window,GLFW_KEY_0)) ++_keys.k["0"]; else _keys.k["0"]=0;
if(glfwGetKey(_window,GLFW_KEY_1)) ++_keys.k["1"]; else _keys.k["1"]=0;
if(glfwGetKey(_window,GLFW_KEY_2)) ++_keys.k["2"]; else _keys.k["2"]=0;
if(glfwGetKey(_window,GLFW_KEY_3)) ++_keys.k["3"]; else _keys.k["3"]=0;
if(glfwGetKey(_window,GLFW_KEY_4)) ++_keys.k["4"]; else _keys.k["4"]=0;
if(glfwGetKey(_window,GLFW_KEY_5)) ++_keys.k["5"]; else _keys.k["5"]=0;
if(glfwGetKey(_window,GLFW_KEY_6)) ++_keys.k["6"]; else _keys.k["6"]=0;
if(glfwGetKey(_window,GLFW_KEY_7)) ++_keys.k["7"]; else _keys.k["7"]=0;
if(glfwGetKey(_window,GLFW_KEY_8)) ++_keys.k["8"]; else _keys.k["8"]=0;
if(glfwGetKey(_window,GLFW_KEY_9)) ++_keys.k["9"]; else _keys.k["9"]=0;
if(glfwGetKey(_window,GLFW_KEY_LEFT)) ++_keys.k["left"]; else _keys.k["left"]=0;
if(glfwGetKey(_window,GLFW_KEY_RIGHT)) ++_keys.k["right"]; else _keys.k["right"]=0;
if(glfwGetKey(_window,GLFW_KEY_UP)) ++_keys.k["up"]; else _keys.k["up"]=0;
if(glfwGetKey(_window,GLFW_KEY_DOWN)) ++_keys.k["down"]; else _keys.k["down"]=0;
if(glfwGetKey(_window,GLFW_KEY_ESCAPE)) ++_keys.k["esc"]; else _keys.k["esc"]=0;
if(glfwGetKey(_window,GLFW_KEY_SPACE)) ++_keys.k["space"]; else _keys.k["space"]=0;
if(glfwGetKey(_window,GLFW_KEY_RIGHT_SHIFT)) ++_keys.k["Rshift"]; else _keys.k["Rshift"]=0;
if(glfwGetKey(_window,GLFW_KEY_LEFT_SHIFT)) ++_keys.k["Lshift"]; else _keys.k["Lshift"]=0;
}
texture* app::getTexture(const std::string &textname){
return &_textures[textname];
}
void app::addTexture(const std::string &name,const std::string&path){
_textures[name]=imgLoader::loadPNG(path);
}
app::~app()
{
}
