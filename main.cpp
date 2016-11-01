#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgLoader.h"
#include <iostream>
#include <string>
#include "sprite.h"
#include "GLSLthingy.h"
#include <memory>
#include "texture.h"
#include "pic.h"
#include <fstream>
#include "app.h"
#include <ctime>
#include "manager.h"
#include <time.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
#include <glm/glm.hpp>
#include "camera2D.h"
#include "SpriteBatch.h"
//aaaaaaaaaaaaaaaa
#include "player.h"
#include "human.h"
#include "projectile.h"
#include "block.h"
#include <utility>
#include <unordered_map>
#include <array>
//#include "vertex.h"
#define STOCK_UV glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)
#define print std::cout<<
#define TIME_TEST_START	time_t start;\
	time_t end;\
	start = time(NULL);


#define TIME_TEST_END end = time(NULL);\
	std::cout<<end-start<<std::endl;
bool pointInBox(glm::vec2 a,glm::vec4 b){
if(a.x>b.x&&a.x<b.x+b.z&&a.y>b.y&&a.y<b.y+b.w) return true;
return false;
}
int checkCollision(glm::vec4 a,glm::vec4 b){
if(pointInBox(glm::vec2(a.x+a.z,a.y),b))return 1;
if(pointInBox(glm::vec2(a.x,a.y),b))return 2;
if(pointInBox(glm::vec2(a.x,a.y+a.w),b))return 3;
if(pointInBox(glm::vec2(a.x+a.z,a.y+a.w),b))return 4;
//return pointInBox(a.x+a.z,b):1?(pointInBox(a.x,b)):2?(pointInBox(a.y+a.w,b)):3?(pointInBox(a.y,b)):4?0
return 0;
}
template <class T>
void mySwap(T& a,T& b){
    if(&a==&b) return;
    T temp=a;
    a = b;
    b=temp;
}
int getRomanNum(const char& ch){
if(ch=='I')return 1;
if(ch=='V')return 5;
if(ch=='X')return 10;
if(ch=='L')return 50;
if(ch=='C')return 100;
if(ch=='D')return 500;
return 1000;
}
void s2_2012(){
    std::string input;
	int val=0;
	std::cin>>input;
	for(unsigned x = 0;x<input.size();x+=2){
		val+=(input[x]-48)*getRomanNum(input[x+1])*(x+3<input.size()?((getRomanNum(input[x+1]))<getRomanNum(input[x+3])?-1:1):1);
	}//std::cout<<endl;
	std::cout<<std::endl<<val<<std::endl;
}
int maxV(const std::vector<int>& v){
    int t = v[0];
    for(auto &x:v)
        if(x>t)
            t=x;
    return t;
}
int minV(const std::vector<int>& v){
    int t = v[0];
    for(auto &x:v)
        if(x<t)
            t=x;
    return t;
}
int absoluteF(int c){
    if(c>0)return c;
    return c*-1;
}
void s3_2012v1(){
    int sensors=0;
    std::cin>>sensors;
    std::vector<int> readings(sensors);
    int t;
    for(int x =0;x<readings.size();++x)
        std::cin>>readings[x];
    std::vector<int> a(maxV(readings)+1,0);
    for(auto& x:readings){
        ++a[x];
    }
    int highest = a[0]>a[1]?0:1;
    int secondHighest = a[0]>a[1]?1:0;
    std::vector<int> highests(1,highest);
    std::vector<int> secondHighests(1,secondHighest);
    for(int x = 2;x<a.size();++x){
        if(a[x]>a[highest]){
            secondHighest=highest;
            highest=x;
            secondHighests=highests;
            highests.clear();
            highests.push_back(x);
        }
        else if(a[x]==a[highest])
            highests.push_back(x);
        else if(a[x]>a[secondHighest]){
            secondHighests.clear();
            secondHighest=x;
            secondHighests.push_back(x);
        }
        else if(a[x]==a[secondHighest]){
            secondHighests.push_back(x);
        }
    }
    if(highests.size()>=2){
        std::cout<<maxV(highests)-minV(highests)<<std::endl;
        return;
    }
    highest=0;
    for(int x =0;x<secondHighests.size();++x){
        highest=absoluteF(highests[0]-secondHighests[x])>highest?absoluteF(highests[0]-secondHighests[x]):highest;
    }
    std::cout<<highest<<std::endl;
}
void s3_2012v2(){
    int sensors=0;
    std::cin>>sensors;
    std::vector<int> readings(sensors);
    int t;
    for(int x =0;x<readings.size();++x)
        std::cin>>readings[x];
    std::unordered_map<int,int> a;
    std::vector<int> keys;
    for(auto& x:readings){
        //++a[x];
        auto it = a.find(x);
        if(it==a.end()){
            a[x]=1;
            keys.push_back(x);
        }else{++a[x];}
    }
    int highest = a[keys[0]]>a[keys[1]]?0:1;
    int secondHighest = a[keys[0]]>a[keys[1]]?1:0;
    std::vector<int> highests(1,highest);
    std::vector<int> secondHighests(1,secondHighest);
    for(int x = 2;x<keys.size();++x){
        if(a[keys[x]]>a[highest]){
            secondHighest=highest;
            highest=keys[x];
            secondHighests=highests;
            highests.clear();
            highests.push_back(keys[x]);
        }
        else if(a[keys[x]]==a[highest])
            highests.push_back(keys[x]);
        else if(a[keys[x]]>a[secondHighest]){
            secondHighests.clear();
            secondHighest=keys[x];
            secondHighests.push_back(keys[x]);
        }
        else if(a[keys[x]]==a[secondHighest]){
            secondHighests.push_back(keys[x]);
        }
    }
    if(highests.size()>=2){
        std::cout<<maxV(highests)-minV(highests)<<std::endl;
        return;
    }
    highest=0;
    for(int x =0;x<secondHighests.size();++x){
        highest=absoluteF(highests[0]-secondHighests[x])>highest?absoluteF(highests[0]-secondHighests[x]):highest;
    }
    std::cout<<highest<<std::endl;
}
template<class t,int n  >
struct abc{

};

struct bca{

    bca(const int a):abcs(a){
        abc<int,5> sads;
        //std::cout<<abcs;
    };
    const int abcs;

};
template<typename... args>
int testty(args... a){
//std::cout<<a...;
    int s=0;

    return s;
}


struct node{
    node(std::shared_ptr<node> first=0,std::shared_ptr<node> second=0):one(first),two(second){};
    std::shared_ptr<node> one;
    std::shared_ptr<node> two;
    int value;
};
template<class T>
int findFirstInVector(const std::vector<T>& vec,T item){
    for(int x = 0;x<vec;++x){
        if(vec[x]==item)return x;
    }return -1;
}
void s4_2015(){
    struct IH{
        IH(int o,int t):i(0),h(t){}
        int i;
        int h;
    };
    int hull,islands,routesNum;
    std::cin>>hull>>islands>>routesNum;
    std::vector<std::vector<std::array<int,3>>> routes(islands+1);
    for(int x = 0;x<routesNum;++x){
        int a,b,t,h;
        std::cin>>a>>b>>t>>h;
        routes[a].push_back({b,t,h});
        routes[b].push_back({a,t,h});
    }
    int start,end;
    std::cin>>start>>end;
    std::vector<IH> quey(1,IH(start,0));
    std::vector<std::vector<int> > fastestPathPlusHull(islands+1,std::vector<int>(hull,2147000000));
    for(int x = 0;x<hull;++x){
        fastestPathPlusHull[start][x]=0;
    }
    //std::vector<char> flag(islands+1,0);
    while(quey.size()){
        IH c = quey[0];
        //int ch = hullQue[0];
        quey.erase(quey.begin());
        //hullQue.erase(hullQue.begin());
        //if(c==end) continue;
        for(int x = 0;x<routes[c.i].size();++x){
            //std::cout<<c<<std::endl<<ch<<std::endl;
            if(routes[c.i][x][2]+c.h<hull
               &&fastestPathPlusHull[c.i][c.h]+routes[c.i][x][1]<fastestPathPlusHull[routes[c.i][x][0]][c.h+routes[c.i][x][2]]){
                //flag[routes[c][x][0]]=1;
                //que.push_back(routes[c.i][x][0]);
                //hullQue.push_back(c.h+routes[c.i][x][2]);
                quey.emplace_back(routes[c.i][x][0],c.h+routes[c.i][x][2]);
                for(int y = c.h+routes[c.i][x][2];y<hull;++y){
                    if(fastestPathPlusHull[routes[c.i][x][0]][y]<fastestPathPlusHull[c.i][c.h]+routes[c.i][x][1])
                        break;
                    fastestPathPlusHull[routes[c.i][x][0]][y]=fastestPathPlusHull[c.i][c.h]+routes[c.i][x][1];
                }
            }
        }
    }
    /*
    int i = 0;
    for(auto x:fastestPathPlusHull){
        std::cout<<i<<":";

        for(auto y:x){
            std::cout<<y<<" ";
        }std::cout<<std::endl;
        ++i;
    } */
    for(auto x:fastestPathPlusHull[end]){
        //std::cout<<x<<" ";
    }//std::cout<<std::endl;
    /*
    if(fastestPathPlusHull[end].back()!=2147000000)
        std::cout<<fastestPathPlusHull[end].back()<<std::endl;
    else
        std::cout<<-1;/* */
}
void s4_2015v2Run(int island,int hullC,int hullM,int time,std::vector<std::vector<int> >& fastestPathPlusHull,const std::vector<std::vector<std::array<int,3>>>& routes){
    if(time>fastestPathPlusHull[island][hullC]){
        return;
    }for(int x = hullC;x<hullM;++x){
        if(fastestPathPlusHull[island][x]<time)
            break;
        fastestPathPlusHull[island][x]=time;
    }
    for(int x = 0;x<routes[island].size();++x){
        if(hullC+routes[island][x][2]>hullM)//||time+routes[island][x][1]<fastestPathPlusHull[island][hullC])
            continue;
        s4_2015v2Run(routes[island][x][0],hullC+routes[island][x][2],hullM,time+routes[island][x][1],fastestPathPlusHull,routes);
    }
}
void s4_2015v2(){
    int hull,islands,routesNum;
    std::cin>>hull>>islands>>routesNum;
    std::vector<std::vector<std::array<int,3>>> routes(islands+1);
    for(int x = 0;x<routesNum;++x){
        int a,b,t,h;
        std::cin>>a>>b>>t>>h;
        routes[a].push_back({b,t,h});
        routes[b].push_back({a,t,h});
    }
    int start,end;
    std::cin>>start>>end;
    std::vector<std::vector<int> > fastestPathPlusHull(islands+1,std::vector<int>(hull,2147000000));
    s4_2015v2Run(start,0,hull,0,fastestPathPlusHull,routes);
    for(auto x:fastestPathPlusHull[end]){
        //std::cout<<x<<" ";
    }//std::cout<<std::endl;
}
void breadthFirstSearch(const std::shared_ptr<node>& tree){
    //void a(){}
}
int main(int argc,char ** argv){
    //s2_2012();
    //s3_2012v2();
    TIME_TEST_START
    //for(int x = 0;x<60;++x)
    //s4_2015v2();
    //s4_2015v2();
    TIME_TEST_END

    int abca =0;
    abc<int,0> sads;
    //return 0;
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    GLFWwindow* window;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(600, 600, "Hello World", NULL, NULL);
    //window = glfwCreateWindow(1920, 1080, "Hello World", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }
    Color color;
    //GLenum error =glewInit();

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glewExperimental = GL_TRUE;
    if(glewInit()!=GLEW_OK){
        std::cout<<"a"<<std::endl;
        return -1;
    }

    //glfwSwapInterval(1);
    app a(window);
    glm::vec2 tempMoveVec(0,0);
    a.addShader("pics","texture.vert","texture.frag",{"vertPosition","vertColor","vertUV"});
    auto thePlayer=std::make_shared<player>();
    human human1(glm::vec2(20,20));
    std::vector<projectile> projectileList;
    std::vector<block> blocks;
    //auto a =block();
    for(int x = 20;x!=0;--x){
        blocks.emplace_back(60+x*80,0,100,a.getTexture("light_bricks.png").id);
        blocks.emplace_back(-60-x*80,0,100,a.getTexture("light_bricks.png").id);
    }
    double angle;
    while (!glfwWindowShouldClose(window)){
        //std::thread t(a.updateKeys);
        //a.updateKeys();
        a.start();
        //t.join();
        angle = std::atan((a.camera.screenToWorld(a.getMousePos())-thePlayer->getPos()+25.5f).y/(a.camera.screenToWorld(a.getMousePos())-thePlayer->getPos()+25.5f).x);
        tempMoveVec=thePlayer->getPos();
        if(a.getKey("left"))tempMoveVec+=glm::vec2(-4,0);
        if(a.getKey("right"))tempMoveVec+=glm::vec2(4,0);
        for(auto &x:blocks){
            //break;
            glm::vec4 abc = glm::vec4(tempMoveVec.x,tempMoveVec.y,thePlayer->getPosAndSize().z,thePlayer->getPosAndSize().w);
            if(checkCollision(abc,x.getPosAndSize())==4||checkCollision(abc,x.getPosAndSize())==1){
            //if(checkCollision(glm::vec4(tempMoveVec.x,tempMoveVec.y,thePlayer->getPosAndSize().z,thePlayer->getPosAndSize().w),thePlayer->getPosAndSize())){
                tempMoveVec.x = x.getPosAndSize().x-thePlayer->getPosAndSize().z;
                break;
            }
            if(checkCollision(abc,x.getPosAndSize())==3||checkCollision(abc,x.getPosAndSize())==2){
            //if(checkCollision(glm::vec4(tempMoveVec.x,tempMoveVec.y,thePlayer->getPosAndSize().z,thePlayer->getPosAndSize().w),thePlayer->getPosAndSize())){
                tempMoveVec.x = x.getPosAndSize().x+x.getPosAndSize().z;
                break;
            }
            //else{std::cout<<"aa"<<std::endl;}
        }
        if(a.getKey("up"))tempMoveVec+=glm::vec2(0,4);
        if(a.getKey("down"))tempMoveVec+=glm::vec2(0,-4);
        for(auto &x:blocks){
            glm::vec4 abc = glm::vec4(tempMoveVec.x,tempMoveVec.y,thePlayer->getPosAndSize().z,thePlayer->getPosAndSize().w);
            if(checkCollision(abc,x.getPosAndSize())==1||checkCollision(abc,x.getPosAndSize())==2){
                tempMoveVec.y=x.getPosAndSize().y+x.getPosAndSize().w;
                break;
            }
            if(checkCollision(abc,x.getPosAndSize())==3||checkCollision(abc,x.getPosAndSize())==4){
            //if(checkCollision(glm::vec4(tempMoveVec.x,tempMoveVec.y,thePlayer->getPosAndSize().z,thePlayer->getPosAndSize().w),thePlayer->getPosAndSize())){
                tempMoveVec.y = x.getPosAndSize().y-thePlayer->getPosAndSize().w;//+thePlayer->getPosAndSize().w;
                break;
            }
        }
        if(tempMoveVec!=thePlayer->getPos()){
            a.camera.setPos(tempMoveVec);
            thePlayer->setPos(tempMoveVec);
        }
        if(a.getMouseButton("left")%5==1){
            std::cout<<angle<<std::endl;
            //fix with trig
            projectileList.emplace_back(glm::vec2(thePlayer->getPosAndSize().x+25.5,thePlayer->getPosAndSize().y+25.5),
                                        (a.camera.screenToWorld(a.getMousePos())-glm::vec2(thePlayer->getPosAndSize().x+25.5,thePlayer->getPosAndSize().y+25.5))*
                                        (float)(10.0f/sqrt(pow((a.camera.screenToWorld(a.getMousePos())-glm::vec2(thePlayer->getPosAndSize().x+25.5,thePlayer->getPosAndSize().y+25.5)).x,2)+
                                        pow((a.camera.screenToWorld(a.getMousePos())-glm::vec2(thePlayer->getPosAndSize().x+25.5,thePlayer->getPosAndSize().y+25.5)).y,2))),
                                        1,
                                        200,
                                        a.getTexture("circle.png").id);
            //std::cout<<projectileList.size()<<std::endl;
        }
        if(a.getMouseButton("right"))std::cout<<a.camera.screenToWorld(a.getMousePos()).x<<" "<<a.camera.screenToWorld(a.getMousePos()).y<<std::endl;

        //for(auto &x:projectileList){

        for(int x = 0;x<projectileList.size();++x){
            bool deadbullet=false;
            if(projectileList[x].update()){
                mySwap(projectileList[x],projectileList[projectileList.size()-1]);
                projectileList.pop_back();
                --x;
                deadbullet=true;
            }
            for(int y = 0;y<blocks.size();++y){
                if(checkCollision(projectileList[x].getPosAndSize(),blocks[y].getPosAndSize())){
                    mySwap(projectileList[x],projectileList[projectileList.size()-1]);
                    projectileList.pop_back();
                    --x;
                    blocks[y].loseHP(20);
                    deadbullet=true;
                    break;
                }
            }
            if(!deadbullet)
                a.draw(projectileList[x].getPosAndSize(),STOCK_UV,projectileList[x].getText(),Color(0,0,0,255),1.0f);
        }//a.draw(glm::vec4(0,60,30,30),STOCK_UV,a.getTexture("circle.png").id,Color(0,0,0,255),1.0f);
        for(int x = 0;x<blocks.size();++x){
            if(blocks[x].getHP()<=0){
                mySwap(blocks[x],blocks[blocks.size()-1]);
                blocks.pop_back();
                --x;
                continue;
            }
            a.draw(blocks[x].getPosAndSize(),STOCK_UV,blocks[x].getText(),Color(),1.0);
            //std::cout<<blocks[x].getText()<<std::endl;
        }
        human1.update();
        //a.draw(human1.getPosAndSize(),STOCK_UV,a.getTexture("circle.png").id,Color(200,200,200,255),1.0f);
        a.draw(thePlayer->getPosAndSize(),STOCK_UV,a.getTexture("circle.png").id,Color(0,200,200,255),1.0f);
        a.end();
    }
    glfwTerminate();
    return 0;
}
