//
//  db_linkList.cpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/26.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//

#include "db_linkList.hpp"
#include <iostream>

DBLinkList::DBLinkList(){
    root=nullptr;
    len =0 ;
}

DBLinkList::~DBLinkList(){
    DBNode *ptr=root;
    if(ptr==nullptr){
    }
    while (ptr) {
        DBNode *tmp=ptr;
        ptr=ptr->getNextNode();
        delete tmp;
    }
    root=nullptr;
    len =0 ;
}

int DBLinkList::length(){
    return len;
}

bool DBLinkList::insertPost(DBNode * input, DBNode *target){
    len++;
    if(target!=nullptr){// not empty
        target->setNextNode(input);//target next is input
        return true;
    }else{
        root=input;
        return false;// first node insert
    }
}

bool DBLinkList::insertPre(DBNode * input){
    len++;
    insertPost(root,input);//input next is old root
    root=input;//update root to input
    return true;
}

bool DBLinkList::insertUp(DBNode *input){
    len++;
    //case:root is null
    if (root==nullptr) {
        root=input;
        return true;
    }
    //case:only has one node
    if(root->getNextNode()==nullptr){
        if( root->getScore()>input->getScore()){
            insertPre(input); len-=2;
        }else{
            insertPost(input, root); len--;
        }
        return true;
    }
    //case:have more than one node
    else{
        DBNode * ptrPost=root->getNextNode();//ptr is for node after current
        DBNode * ptr=root;//current
        
        if(root->getScore()>input->getScore()){//input is lower than root node
            insertPre(input);//insert node to pre
            len-=2;
            return true;
        }else{//input is bigger than root
            while (ptrPost) {
                if(input->getScore()<ptrPost->getScore()){//find current after is bigger than input
                    break;
                }
                ptr=ptrPost;//move next
                ptrPost=ptrPost->getNextNode();////move next
            }
            input->setNextNode(ptrPost);//input next is current after
            ptr->setNextNode(input);//current after is input
            return true;
        }
    }
}
void DBLinkList::print(){
    DBNode *ptr=root;
    while (ptr) {
        ptr->print();
        std::cout << " -> ";
        ptr=ptr->getNextNode();
    }
    std::cout << "||";
}
DBNode * DBLinkList::searchNode(int score){
    if(root==nullptr){//do not have any node
        return nullptr;
    }
    else{//have single node
        if(root->getNextNode()==nullptr){//only one node
            if(root->getScore()==score){//check if equal
                DBNode * node =root;
                return node;
            }
            else{
                return nullptr;
            }
        }
        else{//more than one node
            DBNode *ptr=root;
            int tmp=0;
            while (ptr) {
                if(ptr->getScore()==score){
                    tmp=1;
                    break;
                }else{
                    ptr=ptr->getNextNode();
                }
            }
            if(tmp){
                return ptr;
            }else{
                return nullptr;
            }
        }
    }
}

bool DBLinkList::deleteNode(int score){
    if(root==nullptr){//do not have any node
        return false;
    }
    else{//have single node
        if(root->getNextNode()==nullptr){//only one node
            if(root->getScore()==score){//check if equal
                root=nullptr;
                return true;
            }
            else{
                return false;
            }
        }
        else{//more than one node
            int tmp=0;
            DBNode * ptrPost=root->getNextNode();//ptr is for node after current
            DBNode * ptr=root;//current
            while (ptrPost) {
                if(score==ptrPost->getScore()){//find current after is equal than input
                    tmp=1;
                    break;
                }
                ptr=ptrPost;//move next
                ptrPost=ptrPost->getNextNode();////move next
            }
            if(tmp){
                ptr->setNextNode(ptrPost->getNextNode());
                return true;
            }
            else{
                return false;
            }
        }
    }
}
