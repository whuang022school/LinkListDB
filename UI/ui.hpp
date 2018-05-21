//
//  ui.hpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/26.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//

#ifndef ui_hpp
#define ui_hpp

#include <stdio.h>
#include "db_node.hpp"
#include "db_linkList.hpp"
class UI{
    private :
    DBLinkList * list;
    bool session=false;
    void displayMenu();
    DBNode * getInputNode();
    int      getUserChose();
public:
    UI();
    ~UI();
    void startSession();
};
#endif /* ui_hpp */
