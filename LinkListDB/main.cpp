//
//  main.cpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/19.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//
//
//  LinkListDB
//
//  This project is just a best practices for data structure - link list
//  The LinkListDB obtains insert data with sorted by value,search data,delete data and print out full link list.
//
//
#include "unit_test.hpp"
#include <assert.h>
#include <iostream>
#include "db_node.hpp"
#include "str.hpp"
#include "db_linkList.hpp"
#include "ui.hpp"

void unitTest(){
    testStr_length();
    testStr_Str();
    testDBNode_DBNode();
    testDBNode_Ｎame();
    testDBNode_Score();
    testDBLinkList_DBLinkList();
}
int main(int argc, const char * argv[]) {
    unitTest();
    UI * app =new UI();
    app->startSession();
    delete app;
    return 0;
}
