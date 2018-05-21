//
//  db_linkList.hpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/26.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//

#ifndef db_linkList_hpp
#define db_linkList_hpp

#include <stdio.h>
#include "str.hpp"
#include "db_node.hpp"

class DBLinkList{
    private:
    DBNode * root;
    int len=0;
    int countLength();
    
    public :
    DBLinkList();
    ~DBLinkList();
    int length();//the length of full link list
    void print();//print out full link list
    bool deleteNode(int score);//delete the node if exist success true faild false
    DBNode*  searchNode(int score);//find if node exist return the node or null
    bool insertUp(DBNode *);//insert a single node with value going up (sorted list)
    bool insertPre(DBNode * );//insert a single node at pre postion
    bool insertPost(DBNode *,DBNode *);//insert a single node at post position
};

#endif /* db_linkList_hpp */
