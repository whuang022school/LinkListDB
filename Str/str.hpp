//
//  str.hpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/19.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//

#ifndef str_hpp
#define str_hpp

#include <stdio.h>
#include <limits.h>
class Str{
private:
    char *str;
    int maxlen=INT_MAX-1;
    int len=0;
    int countLength();
    int countLength(char*);
public:
    Str(char *);
    ~Str();
    void printStr();
    int length();
    char at(int pos);
    bool operator==(const char * b);
};


#endif /* str_hpp */
