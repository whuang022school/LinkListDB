//
//  ui.cpp
//  LinkListDB
//
//  Created by 明翰  楊 on 2018/4/26.
//  Copyright © 2018年 明翰  楊. All rights reserved.
//

#include "ui.hpp"
#include <iostream>

UI::UI(){
    list=new DBLinkList();
}
UI::~UI(){
    delete list;
}
void UI::displayMenu(){
    
    std::cout << "\n---------------------\n";
    std::cout << "--Link List DB Menu--\n";
    std::cout << "--1.Insert Node (1)--\n";
    std::cout << "--2.Delete Node (2)--\n";
    std::cout << "--3.Search Node (3)--\n";
    std::cout << "--4.Print  Node (4)--\n";
    std::cout << "--5.Quit   EXE  (5)--\n";
    std::cout << "---------------------\n";
}
int  UI:: getUserChose(){
    std::cin.clear();
    fflush(stdin);
    int temp=0;
    std::cout << "\nPlease input a number \n";
    std::cin>>temp;
    return temp;
}

DBNode * UI:: getInputNode(){
    std::cin.ignore();
    std::cin.clear();
    std::cout << "\nPlease input a user name \n";
    fflush(stdin);
    char *nameIn=new char[30];
    std::cin.getline(nameIn,30);
    std::cout << "\nPlease input a user score \n";
    int score;
    std::cin.clear();
    fflush(stdin);
    std::cin >> score;
    DBNode *user=new DBNode(score,nameIn);
    return user;
}

void UI::startSession(){
    session=true;
    int chose=0;
    while (session) {
        displayMenu();
        chose=getUserChose();
        switch (chose) {
            case 1:
                list->insertUp(getInputNode());
                break;
            case 2:{
                bool tmp=list->deleteNode(getUserChose());
                if(tmp){
                    std::cout << "success delete data! \n";
                }else{
                    std::cout << "data not exit! can not delete data!\n";
                }
                break;
            }
            case 3:{
                DBNode * user=list->searchNode(getUserChose());
                if(user!=nullptr){
                    user->print();
                }
                else{
                    std::cout << "data not exit! \n";
                }
                break;
            }
            case 4:
                list->print();
                break;
            case 5:
                return ;
            default:
                break;
        }
    }
}


