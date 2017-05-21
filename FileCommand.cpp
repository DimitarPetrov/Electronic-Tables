//
// Created by Dimitar on 21.5.2017 г..
//

#include "FileCommand.h"

#include <iostream>
#include "FileCommands.h"
#include <cstring>

const char* FileCommand::getName() const{
    return name;
}
const char* FileCommand::getPath() const{
    return path;
}

FileCommand::FileCommand(const char* n, const char* p){
    name = new char [strlen(n)+1];
    strcpy(name,n);
    path = new char [strlen(p)+1];
    strcpy(path,p);
}

FileCommand::FileCommand(const FileCommand& a){
    Copy(a);
}

FileCommand& FileCommand::operator= (const FileCommand& a){
    if(this == &a){
        return *this;
    }
    delete[]name;
    delete[]path;
    Copy(a);
    return *this;
}

FileCommand::~FileCommand(){
    delete[]name;
    delete[]path;
}

bool FileCommand::operator==(const FileCommand& a){
    return !(strcmp(name, a.name));
}

std::istream& operator>>(std::istream& in, FileCommand& a){
    FileCommand tmp;
    delete[]tmp.name;
    delete[]tmp.path;
    tmp.name = new char[1024];
    tmp.path = new char[1024];
    in>>tmp.name;
    in.get();
    if(!(strcmp(tmp.name,"open")) || !(strcmp(tmp.name, "saveas"))){
        in.getline(tmp.path,1024);
    }
    a = tmp;
    return in;
}
std::ostream& operator<<(std::ostream& out, const FileCommand& a){
    out<<a.name<<"\n"<<a.path<<std::endl;
    return out;
}

void FileCommand::Copy(const FileCommand& a){
    name = new char [strlen(a.name)+1];
    strcpy(name,a.name);
    path = new char [strlen(a.path)+1];
    strcpy(path,a.path);
}
