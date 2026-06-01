#pragma once

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<sstream>
#include<string>
#include "colors.hpp"
#include<vector>

template<typename T>
class Nde{
public:
    T data;
    Nde<T>* prev;
    Nde<T>* next;

    Nde(T val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

template<typename T>
class Doubly{
public:
    Nde<T>* head;
    Nde<T>* tail;

    Doubly(){
        head = nullptr;
        tail = nullptr;
    }

    void insertBegin(T val){
        Nde<T>* tmp = new Nde<T>(val);
        if(!head){
            head = tmp;
            tail = tmp;
            return;
        }
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
    void insertEnd(T val){
        Nde<T>* tmp = new Nde<T>(val);
        if(!tail){
            head = tmp;
            tail = tmp;
            return;
        }
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
    void insertAfter(T key,T val){
        Nde<T>* tmp = head;
        while(tmp && tmp->data!=key){
            tmp = tmp->next;
        }
        if(!tmp){
            std::cout<<Color::BG_RED<<"Key not Found!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        Nde<T>* dum = new Nde<T>(val);
        dum->next = tmp->next;
        dum->prev = tmp;
        if(tmp->next){
            tmp->next->prev = dum;
        }else{
            tail = dum;
        }
        tmp->next = dum;
        std::cout<<"\n\n";
        std::cout<<Color::BGREEN<<"Value Inserted successfully.."<<Color::RESET;
        std::cout<<"\n\n";
    }
    void insertBefore(T key,T val){
        Nde<T>* tmp = head;
        while(tmp && tmp->data != key){
            tmp = tmp->next;
        }
        if(!tmp){
            std::cout<<Color::BG_RED<<"Key not Found!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        Nde<T>* dum = new Nde<T>(val);
        dum->next = tmp;
        dum->prev = tmp->prev;
        if(tmp->prev){
            tmp->prev->next = dum;
        }else{
            head = dum;
        }
        tmp->prev = dum;
        std::cout<<"\n\n";
        std::cout<<Color::BGREEN<<"Value Inserted successfully.."<<Color::RESET;
        std::cout<<"\n\n";
    }

    void deleteBegin(){
        if(!head){
            std::cout<<Color::BG_RED<<"No Elements!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        Nde<T>* tmp = head;
        if(head==tail){
            head = nullptr;
            tail = nullptr;
        }else{
            head = head->next;
            head->prev = nullptr;
        }
        delete tmp;
    }
    void deleteEnd(){
        if(!tail){
            std::cout<<Color::BG_RED<<"No Elements!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        Nde<T>* tmp = tail;
        if(head==tail){
            head = nullptr;
            tail = nullptr;
        }else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete tmp;
    }
    void deleteKey(T key){
        Nde<T>* tmp = head;
        while(tmp && tmp->data != key){
            tmp = tmp->next;
        }
        if(!tmp){
            std::cout<<Color::BG_RED<<"Key not Found!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        if(tmp==head){
            deleteBegin();
        }else if(tmp==tail){
            deleteEnd();
        }else{
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
        }
        std::cout<<Color::BG_YELLOW<<"Deleting..."<<Color::RESET<<"\n\n";
        Sleep(2000);
        std::cout<<Color::BG_RED<<"Deleted successfully"<<Color::RESET<<"\n\n";
    }

    int searchKey(T key){
        Nde<T>* tmp = head;
        int pos = 1;
        while(tmp){
            if(tmp->data==key){
                return pos;
            }
            tmp = tmp->next;
            pos++;
        }
        return -1;
    }

    void visualize(){
        std::cout<<"\n";
        if(!head){
            std::cout<<Color::BG_GREEN<<"  HEAD ──► nullptr"<<Color::RESET<<"\n";
            std::cout<<Color::BG_CYAN<<"  Empty list"<<Color::RESET<<"\n";
            return;
        }

        std::vector<Nde<T>*> Ndes;
        for(Nde<T>* cur = head; cur; cur = cur->next){
            Ndes.push_back(cur);
        }

        std::cout << "        ";
        for(auto* n : Ndes){
            std::cout<<std::left<<std::setw(28)<<(void*)n;
        }
        std::cout<<"\n";

        std::cout<<Color::BBLUE<<"HEAD ──► "<<Color::RESET;
        for (int i = 0; i < Ndes.size(); i++){
            std::cout<<Color::BYELLOW<<"┌────────────────┐"<<Color::RESET;
            if(i+1 < Ndes.size()){
                std::cout<<"     ";
            }
        }
        std::cout << "\n";

        std::cout << "         ";
        for(int i = 0; i < Ndes.size(); i++){
            std::cout<<Color::BYELLOW<<"|"<<Color::RESET;
            std::cout<<" data: "<<std::setw(6)<<std::left<<Ndes[i]->data<<"   ";
            std::cout<<Color::BYELLOW<<"|"<<Color::RESET;
            if(i+1 < Ndes.size()){
                std::cout<<Color::BGREEN<<" ──► "<<Color::RESET;
            }
        }
        std::cout<<"\n";

        std::cout << "         ";
        for(int i = 0; i < Ndes.size(); i++){
            std::string nextStr;
            if(Ndes[i]->next){
                std::ostringstream ss;
                ss<<(void*)Ndes[i]->next;
                nextStr = ss.str();
            }else{
                nextStr = "nullptr";
            }
            std::cout<<Color::BYELLOW<<"|"<<Color::RESET;
            std::cout<<" next: "<<std::left<<std::setw(9)<<nextStr;
            std::cout<<Color::BYELLOW<<"|"<<Color::RESET;
            if(i+1 < Ndes.size()){
                std::cout<<" ◄── ";
            }
        }
        std::cout<<"\n";

        std::cout<<"         ";
        for(int i = 0; i < Ndes.size(); i++){
            std::cout<<Color::BYELLOW<<"└────────────────┘"<<Color::RESET;
            if(i+1 < Ndes.size()){
                std::cout<<"     ";
            }
        }
        std::cout<<"\n";

        std::cout<<"         ";
        for(int i = 0; i < Ndes.size(); i++){
            if(i+1 == Ndes.size()){
                std::cout<<"              ";
                std::cout<<Color::BG_YELLOW<<"▲ TAIL"<<Color::RESET;
            }else{
                std::cout<<"                     ";
            }
        }
        std::cout<<"\n\n";
        //std::cout<<Color::BG_BLUE<<"  size: "<<size<<" "<<Color::RESET;
        if(head){
            std::cout<<"|";
            std::cout<<Color::BG_GREEN<<" head→val: "<<head->data<<" "<<Color::RESET;
        }
        if(tail){
            std::cout<<"|";
            std::cout<<Color::BG_CYAN<<" tail→val: "<<tail->data<<" "<<Color::RESET<<"|"<<Color::MAGENTA<<" tail→next: nullptr"<<Color::RESET;
        }
        std::cout<<"\n\n";
    }

    void options(){
        std::cout<<Color::BMAGENTA<<"[0]"<<Color::RESET;
        std::cout<<"insert_at_beginning   ";
        std::cout<<Color::BMAGENTA<<"[1]"<<Color::RESET;
        std::cout<<"insert_at_end \n";

        std::cout<<Color::BMAGENTA<<"[2]"<<Color::RESET;
        std::cout<<"insert_after_a_given_key   ";
        std::cout<<Color::BMAGENTA<<"[3]"<<Color::RESET;
        std::cout<<"insert_before_a_given_key \n";

        std::cout<<Color::BMAGENTA<<"[4]"<<Color::RESET;
        std::cout<<"visualize   ";
        std::cout<<Color::BMAGENTA<<"[5]"<<Color::RESET;
        std::cout<<"delete_at_beginning   ";
        std::cout<<Color::BMAGENTA<<"[6]"<<Color::RESET;
        std::cout<<"delete_at_end \n";

        std::cout<<Color::BMAGENTA<<"[7]"<<Color::RESET;
        std::cout<<"delete_key ";
        std::cout<<Color::BMAGENTA<<"[8]"<<Color::RESET;
        std::cout<<"search_key \n";

        std::cout<<Color::BMAGENTA<<"[9]"<<Color::RESET;
        std::cout<<Color::BRED<<"EXIT "<<Color::RESET<<"\n";
    }
    void menu(){
        options();
        int choice; 
        std::string ch;
        while(true){
            std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
            std::cin>>ch;
            if(ch.size()==1 && ch[0]>='0' && ch[0]<='9'){
                break;
            }
            std::cout<<"\n\n\n";
            std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
        }

        choice = std::stoi(ch);
        std::cout<<"\n\n";
        if(choice==0){
            std::cout<<Color::BG_YELLOW<<"Inserting Value at the Beginning"<<Color::RESET<<"\n\n";
            std::cout<<"Enter value to insert: ";
            T val;
            std::cin>>val;
            insertBegin(val);
            std::cout<<"\n\n";
            std::cout<<Color::BGREEN<<"Value Inserted successfully.."<<Color::RESET;
            std::cout<<"\n\n";
            menu();
        }else if(choice==1){
            std::cout<<Color::BG_YELLOW<<"Inserting Value at the End"<<Color::RESET<<"\n\n";
            std::cout<<"Enter value to insert: ";
            T val;
            std::cin>>val;
            insertEnd(val);
            std::cout<<"\n\n";
            std::cout<<Color::BGREEN<<"Value Inserted successfully.."<<Color::RESET;
            std::cout<<"\n\n";
            menu();
        }else if(choice==2){
            std::cout<<Color::BG_YELLOW<<"Inserting Value after a given key"<<Color::RESET<<"\n\n";
            T val;
            T target;
            std::cout<<Color::BLUE<<"Enter key: "<<Color::RESET;
            std::cin>>target;
            std::cout<<"\n";
            std::cout<<Color::BYELLOW<<"Enter value to insert: "<<Color::RESET;
            std::cin>>val;
            insertAfter(target,val);
            menu();
        }else if(choice==3){
            std::cout<<Color::BG_YELLOW<<"Inserting Value before a given key"<<Color::RESET<<"\n\n";
            T val;
            T target;
            std::cout<<Color::BLUE<<"Enter key: "<<Color::RESET;
            std::cin>>target;
            std::cout<<"\n";
            std::cout<<Color::BYELLOW<<"Enter value to insert: "<<Color::RESET;
            std::cin>>val;
            insertBefore(target,val);
            menu();
        }else if(choice==4){
            std::cout<<"\n\n";
            std::cout<<Color::BG_YELLOW<<"VISUALIZER"<<Color::RESET<<" :\n";
            visualize();
            std::cout<<"\n\n";
            menu();
        }else if(choice==5){
            std::cout<<"\n\n";
            std::cout<<Color::BG_YELLOW<<"Deleting at the beginning"<<Color::RESET<<"\n\n";
            deleteBegin();
            Sleep(2000);
            std::cout<<Color::BG_RED<<"Deleted successfully"<<Color::RESET<<"\n\n";
            menu();
        }else if(choice==6){
            std::cout<<"\n\n";
            std::cout<<Color::BG_YELLOW<<"Deleting at the end"<<Color::RESET<<"\n\n";
            deleteEnd();
            Sleep(2000);
            std::cout<<Color::BG_RED<<"Deleted successfully"<<Color::RESET<<"\n\n";
            menu();
        }else if(choice==7){
            std::cout<<"\n\n";
            std::cout<<Color::BG_YELLOW<<"Deleting key"<<Color::RESET<<"\n\n";
            std::cout<<"\n\n";
            T key;
            std::cout<<Color::BLUE<<"Enter key: "<<Color::RESET;
            std::cin>>key;
            std::cout<<"\n\n";
            deleteKey(key);
            menu();
        }else if(choice==8){
            std::cout<<"\n\n";
            std::cout<<Color::BG_YELLOW<<"Searching key"<<Color::RESET<<"\n\n";
            std::cout<<"\n\n";
            T key;
            std::cout<<Color::BLUE<<"Enter key: "<<Color::RESET;
            std::cin>>key;
            std::cout<<"\n\n";
            int p = searchKey(key);
            if(p==-1){
                std::cout<<"\n\n";
                std::cout<<Color::BG_RED<<"Key Not Found!!"<<Color::RESET<<"\n\n";
            }else{
                std::cout<<"\n\n";
                std::cout<<Color::BG_GREEN<<"Key Found at the position "<<Color::BG_BLUE<<pos<<Color::RESET<<"\n\n";
            }
            menu();
        }else if(choice==9){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Exiting Doubly Linked List...."<<Color::RESET;
            std::cout<<"\n\n";
            Sleep(2000);
            return;
        }
    }
};