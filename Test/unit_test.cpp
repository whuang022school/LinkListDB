//
//  str_unit_test.cpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/26.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//
#include "db_node.hpp"
#include "str.hpp"
#include <assert.h>
#include <string>
#include "unit_test.hpp"
#include "db_linkList.hpp"

void testStr_length(){
    char *testPtr =new char[5];
    testPtr[0]='T';testPtr[1]='E';testPtr[2]='S';testPtr[3]='T';testPtr[4]='\0';
    Str *str =new Str(testPtr);
    assert(str->length()==4);
    delete str;
    str=nullptr;
    delete []testPtr;
    testPtr=nullptr;
}

void testStr_Str(){
    char *testPtr =new char[5];
    testPtr[0]='T';testPtr[1]='E';testPtr[2]='S';testPtr[3]='T';testPtr[4]='\0';
    Str *str =new Str(testPtr);
    assert(*str==(testPtr));
    delete str;
    str=nullptr;
    delete []testPtr;
    testPtr=nullptr;
}

void testDBNode_DBNode(){
    char *testPtr =new char[5];
    testPtr[0]='T';testPtr[1]='E';testPtr[2]='S';testPtr[3]='T';testPtr[4]='\0';
    DBNode * node=new DBNode(100,testPtr);
    assert(node->getScore()==100&& *node->getName()==testPtr);
    delete node;
    node=nullptr;
    delete []testPtr;
    testPtr=nullptr;
}

void testDBNode_Ｎame(){
    char *testName =new char[5];
    testName[0]='T';testName[1]='E';testName[2]='S';testName[3]='T';testName[4]='\0';
    char *testName2 =new char[5];
    testName2[0]='A';testName2[1]='B';testName2[2]='C';testName2[3]='D';testName2[4]='\0';
    DBNode * node=new DBNode(100,testName);
    node->setName(testName2);
    assert(node->getScore()==100&& *node->getName()==testName2);
    delete []testName;
    delete [] testName2;
    delete node;
    testName=nullptr;
    testName2=nullptr;
    node=nullptr;
}

void testDBNode_Score(){
    
    char test[5]={'T','E','S','T','\0'};
    char *testStr=test;
    DBNode * node=new DBNode(100,testStr);
    node->setScore(50);
    assert(node->getScore()==50);
}


void testDBLinkList_DBLinkList(){
    
    //Test Node 0
    char test[5]={'T','E',' ','0','\0'};
    char *testStr=test;
    DBNode * node0=new DBNode(100,testStr);
    
    //Test Node 1
    char test1[5]={'T','E',' ','1','\0'};
    char *testStr1=test1;
    DBNode * node1=new DBNode(-100,testStr1);
    
    //Test Node 2
    char test2[5]={'T','E',' ','2','\0'};
    char *testStr2=test2;
    DBNode * node2=new DBNode(50,testStr2);
    
    //Test Node 3
    char test3[5]={'T','E',' ','3','\0'};
    char *testStr3=test3;
    DBNode * node3=new DBNode(10,testStr3);
    DBLinkList *list =new DBLinkList();
    list->insertUp(node0);
    list->insertUp(node1);
    list->insertUp(node2);
    list->insertUp(node3);
    assert(list->length()==4);
    assert(list->searchNode(-100)==node1);
    delete list;

}



















