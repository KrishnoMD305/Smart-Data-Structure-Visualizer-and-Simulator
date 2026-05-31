#pragma once

#include<iostream>
#include "colors.hpp"

template<typename T>
class Node{
public:
    T data;
    Node* prev;
    Node* next;

    Node(T val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

template<typename T>
class Doubly{
public:
    Node* head;
    Node* tail;

    Doubly(){
        head = nullptr;
        tail = nullptr;
    }

    void insertBegin(T val){
        Node* tmp = new Node(val);
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
        Node* tmp = new Node(val);
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
        Node* tmp = head;
        while(tmp && tmp->data!=key){
            tmp = tmp->next;
        }
        if(!tmp){
            std::cout<<Color::BG_RED<<"Key not Found!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        Node* dum = new Node(val);
        dum->next = tmp->next;
        dum->prev = tmp;
        if(tmp->next){
            tmp->next->prev = dum;
        }else{
            tail = dum;
        }
        tmp->next = dum;
    }
};