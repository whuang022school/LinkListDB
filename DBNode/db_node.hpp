//
//  db_node.hpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/19.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//

#ifndef db_node_hpp
#define db_node_hpp

#include <stdio.h>
#include "str.hpp"

class DBNode {
public:
    
    DBNode(int,char *);
    ~DBNode();
    
    void setScore(int );
    int getScore();
    
    Str *getName();
    void setName(char *);
    void print();
    
    void setNextNode(DBNode *);
    DBNode * getNextNode();
    
private:
    int score=0;
    DBNode * nextNode;
    Str * name;
};
#endif /* db_node_hpp */
