//
//  db_node.cpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/19.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//

#include <iostream>
#include "db_node.hpp"
using namespace std;
DBNode:: DBNode(int score,char * name){
    this->name=new Str(name);
    this->score=score;
    this->nextNode=nullptr;
}

void DBNode::setName(char *name){
    Str *tmp=this->getName();
    delete tmp;
    Str *ntmp=new Str(name);
    this->name=ntmp;
}

void DBNode::setScore(int score){
    this->score=score;
    
}

int DBNode::getScore(){
    return this->score;
}

Str* DBNode::getName(){
    return this->name;
}

DBNode::~DBNode(){
    delete name;
    name=nullptr;
    nextNode=nullptr;
}

DBNode * DBNode::getNextNode(){
    DBNode * ptr=nextNode;
    return ptr;
}

void DBNode:: setNextNode(DBNode * nextNode){
    this->nextNode=nextNode;
}

void DBNode::print(){
    cout<<"{ ";
    cout<<"Name : ";
    this->name->printStr();
    cout<<" , ";
    cout<<"Score : ";
    cout << this->getScore();
    cout<<" }";
}
