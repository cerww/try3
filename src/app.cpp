#include "app.h"
app::app(GLFWwindow* &window):_window(window),_ypos(0.0f),_xpos(0.0f),_maxFPS(60){
    _spriteBatch.init();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
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
    camera.init(width,height);
}
int app::getKey(const std::string &key){
return _keys.k[key];
}
//GLuint manager::currentTextId=0;
int app::getMouseButton(const std::string &Button){
return _keys.m[Button];
}
void app::test(){
int a;
}
glm::vec2 app::getMousePos(){
return m_mousePos;
}
void app::start(){
    //std::thread t(&app::updateKeys,this);
    //drawing
    updateKeys();
    _GLSLstuffs["pics"]->use();
    glActiveTexture(GL_TEXTURE0);
    GLint textlocate=_GLSLstuffs["pics"]->getUniformLocate("Text");
    glUniform1i(textlocate,0);

    GLint camLocate=_GLSLstuffs["pics"]->getUniformLocate("orthiMat");
    glm::mat4 abc = camera.getCamMatrix();
    glUniformMatrix4fv(camLocate,1,GL_FALSE,&abc[0][0]);
    //t.join();
    _spriteBatch.begin();
}
void app::update(){
    glfwSwapBuffers(_window);
    //manager::currentCamera.update();
    camera.update();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    /* Poll for and process events */
    glfwPollEvents();
    //mouse
    glfwGetCursorPos(_window,&_xpos,&_ypos);
    //glfwSetCursorPos(_window,100,100);
    m_mousePos = camera.screenToWorld(glm::vec2(_xpos,_ypos));
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
    //drawing
    _GLSLstuffs["pics"]->use();
    glActiveTexture(GL_TEXTURE0);
    GLint textlocate=_GLSLstuffs["pics"]->getUniformLocate("Text");
    glUniform1i(textlocate,0);

    GLint camLocate=_GLSLstuffs["pics"]->getUniformLocate("orthiMat");
    glm::mat4 abc = camera.getCamMatrix();
    glUniformMatrix4fv(camLocate,1,GL_FALSE,&abc[0][0]);
    _spriteBatch.begin();
    //for(int x =0;x<1;++x)
    //_spriteBatch.draw(glm::vec4(0.0f,0.0f,300.0f,300.0f),glm::vec4(0.0f,0.0f,1.0f,1.0f),getTexture("Enemy_broccoli1.png").id,Color(255,255,255),0.0f);
    //_spriteBatch.draw(glm::vec4(0.0f,0.0f,300.0f,300.0f),glm::vec4(0.0f,0.0f,1.0f,1.0f),getTexture("Enemy_broccoli1.png").id,Color(255,255,255),0.0f);
    //_spriteBatch.draw(glm::vec4(0.0f,100.0f,200.0f,300.0f),glm::vec4(0.0f,0.0f,1.0f,1.0f),getTexture("Enemy_broccoli1.png").id,Color(255,255,255),0.0f);
    //_spriteBatch.draw(glm::vec4(0.0f,0.0f,300.0f,300.0f),glm::vec4(0.0f,0.0f,1.0f,1.0f),getTexture("Enemy_broccoli1.png").id,Color(255,255,255),0.0f);
    _spriteBatch.end();
    _spriteBatch.renderBatch();
    _GLSLstuffs["pics"]->unuse();
    //fps limiter
    _fpsLimiter.limitFPS();
}
void app::end(){
    _spriteBatch.end();
    camera.update();
    _spriteBatch.renderBatch();
    _GLSLstuffs["pics"]->unuse();
    //fps limiter
    _fpsLimiter.limitFPS();
}
void app::setMaxFPS(const int&newfps){
_maxFPS=newfps;
}
void app::draw(glm::vec4 dimensions,glm::vec4 uv,GLuint text,Color colour,const float& depth){
_spriteBatch.draw(dimensions,uv,text,colour,depth);
}
texture app::getTexture(const std::string &textname){
    auto it= _textures.find(textname);
    if(it==_textures.end()){
        _textures[textname]=imgLoader::loadPNG(textname);

    }//std::cout<<textname<<std::endl;
    return _textures[textname];
}
/*
void app::addTexture(const std::string &name,const std::string&path){
    auto it= _textures.find(name);
    if(it!=_textures.end()){
        return;
    }
_textures[name]=imgLoader::loadPNG(path);
}*/
std::shared_ptr<GLSLthingy> app::getShader(const std::string& name){
return _GLSLstuffs[name];
}
void app::addShader(const std::string& shaderName,const std::string& vertexFile,const std::string& fragFile,const std::vector<std::string>& attributes){
_GLSLstuffs[shaderName]=std::make_shared<GLSLthingy>();
_GLSLstuffs[shaderName]->compileshad(vertexFile,fragFile);
for(auto x:attributes)
    _GLSLstuffs[shaderName]->addAttribute(x);
_GLSLstuffs[shaderName]->linkshader();
}
void app::addSprite(const std::string&name,const std::shared_ptr<pic>&pic){
_imgs.push_back(pic);
}
bool app::removeSprite(const std::string&name){

return true;
}
void app::updateKeys(){
    glfwSwapBuffers(_window);
    //manager::currentCamera.update();
    camera.update();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    /* Poll for and process events */
    glfwPollEvents();
    glfwGetCursorPos(_window,&_xpos,&_ypos);
    m_mousePos = glm::vec2(_xpos,_ypos);
    //glfwGetCursorPos(_window,&_xpos,&_ypos);
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
app::~app()
{

}

