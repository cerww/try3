#include "GLSLthingy.h"
GLSLthingy::GLSLthingy():programID(0),vertShadID(0),fragShadID(0),numAttribs(0){}

void GLSLthingy::compileshad(const std::string &vertfile,const std::string &fragfile){
    programID = glCreateProgram();
    vertShadID =glCreateShader(GL_VERTEX_SHADER);
    fragShadID =glCreateShader(GL_FRAGMENT_SHADER);
    if(!vertShadID){
        printf("0a");
        glfwTerminate();
    }
    if(!fragShadID){
        printf("0b");
        glfwTerminate();
    }
    compleshady(vertfile,vertShadID);
    compleshady(fragfile,fragShadID);/*
    std::ifstream vertFilePath(vertfile.c_str());
    std::string vertfil="";
    std::string line = "";
    while(std::getline(vertFilePath,line))vertfil+=line;
    vertFilePath.close();
    const char* ContPtr = vertfil.c_str();
    glShaderSource(vertShadID,1,&ContPtr,0);
    glCompileShader(vertShadID);
    GLint success = 0;
    glGetShaderiv(vertShadID,GL_COMPILE_STATUS,&success);
    if(success==GL_FALSE){
        GLint maxl = 0;
        glGetShaderiv(vertShadID,GL_INFO_LOG_LENGTH,&maxl);
        std::vector<char> errorLog(maxl);
        glGetShaderInfoLog(vertShadID,maxl,&maxl,&errorLog[0]);
        glDeleteShader(vertShadID);
    }*/
}
void GLSLthingy::compleshady(const std::string &path,GLuint &ID){
    std::ifstream vertFilePath(path.c_str());
    std::string vertfil="";
    std::string line = "";
    while(std::getline(vertFilePath,line))vertfil+=line+"\n";
    vertFilePath.close();
    //std::cout<<vertfil<<std::endl;//<<vertfil.c_str();
    const char* ContPtr = vertfil.c_str();
    glShaderSource(ID,1,&ContPtr,nullptr);
    glCompileShader(ID);
    GLint success = 0;
    glGetShaderiv(ID,GL_COMPILE_STATUS,&success);
    if(success==GL_FALSE){
        GLint maxl = 0;
        glGetShaderiv(ID,GL_INFO_LOG_LENGTH,&maxl);
        std::vector<char> errorLog(maxl);
        glGetShaderInfoLog(ID,maxl,&maxl,&errorLog[0]);
        glDeleteShader(ID);
        printf("%s\n",&errorLog[0]);
        printf("1\n");
        glfwTerminate();
    }
    }
void GLSLthingy::linkshader(){
glAttachShader(programID,vertShadID);
glAttachShader(programID,fragShadID);
glLinkProgram(programID);
GLint isLinked = 0;
glGetProgramiv(programID,GL_LINK_STATUS,(int*)&isLinked);
if(isLinked==GL_FALSE){
    GLint maxl = 0;
    glGetShaderiv(programID,GL_INFO_LOG_LENGTH,&maxl);
    std::vector<GLchar> errorLog(maxl);
    glGetShaderInfoLog(programID,maxl,&maxl,&errorLog[0]);
    glDeleteProgram(programID);
    glDeleteShader(vertShadID);
    glDeleteShader(fragShadID);
    printf("%s\n",&(errorLog[0]));
    printf("2\n");
    glfwTerminate();
}
glDetachShader(programID,vertShadID);
glDetachShader(programID,fragShadID);
glDeleteShader(vertShadID);
glDeleteShader(fragShadID);
}
void GLSLthingy::addAttribute(const std::string& attribName){
glBindAttribLocation(programID,numAttribs++,attribName.c_str());
//std::cout<<numAttribs<<std::endl;
}
GLSLthingy::~GLSLthingy()
{
    //dtor
}
void GLSLthingy::use(){
glUseProgram(programID);
for(int i =0;i<numAttribs;++i)
    glEnableVertexAttribArray(i);
//std::cout<<programID<<std::endl;
}
void GLSLthingy::unuse(){
glUseProgram(0);
for(int i =0;i<numAttribs;++i)
    glDisableVertexAttribArray(i);
}
GLint GLSLthingy::getUniformLocate(const std::string& uniName){
GLint l =glGetUniformLocation(programID,uniName.c_str());
if(l==GL_INVALID_INDEX){
    printf("3\n %s was not found",&uniName[0]);
    glfwTerminate();
    }
return l;
}

