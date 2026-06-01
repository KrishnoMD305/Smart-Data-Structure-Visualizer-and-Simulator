#pragma once

#include<iostream>
#include "colors.hpp"

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
};