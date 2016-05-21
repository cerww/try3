#include "IOmanager.h"

static bool readFileToBuffer(const std::string& filePath,std::vector<char>& buffer){
    std::fstream file(filePath,std::ios::binary);
    if(file.fail()){
        perror(filePath.c_str());
        return false;
    }
    file.seekg(0,std::ios::beg);
    int filesize = file.tellg();
    //buffer.resize(file.tellg());
    file.seekg(0,std::ios::beg);
    filesize -=file.tellg();
    buffer.resize(filesize);
    file.read(&buffer[0],filesize);
    file.close();
    return true;
}
IOmanager::IOmanager()
{
    //ctor
}

IOmanager::~IOmanager()
{
    //dtor
}
