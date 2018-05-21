//
//  str.cpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/19.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//

#include "str.hpp"
#include <iostream>

Str::Str(char *str){
    int size=countLength(str);
    len=size;
    this->str=new char[size+1];
    memcpy(this->str, str, size);
}

Str::~Str(){
    delete [] str;
    str=nullptr;
}
void Str::printStr(){
    char *ptr=str;
    for(int i=0;i<maxlen;i++){
        if(*(ptr+i)=='\0'){
            break;
        }
        else{
            std::cout<< *(ptr+i);
        }
    }
}

int Str::countLength(){
    return countLength(str);
}

int Str::length(){
    return len;
}

char Str::at(int pos){
    return  char(*(this->str+pos));
}

int Str::countLength(char *ptr){
    int i=1;
    for(i=0;i<maxlen;i++){
        if(*(ptr+i)=='\0'){
            break;
        }
    }
    return i;
}

bool Str::operator==(const char * b){
    bool eq=true;
    for(int i=0;i<len;i++){
        if(*(b+i)=='\0'){
            eq=false;
            return eq;
        }
        if(*(str+i)!=*(b+i)){
            eq=false;
            return eq;
        }
    }
    return eq;
}
/*
char * Str::cloneStr(){
    char *ptrO=str;
    char *ptr=new char[len];
    for(int i=0;i<len;i++){
        ptr[i]=*(ptrO+i);
    }
    return ptr;
}*/

