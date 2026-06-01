#pragma once

#include<iostream>
#include "colors.hpp"

template<typename T>
class Node{
public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

template<typename T>
class Doubly{
public:
    Node<T>* head;
    Node<T>* tail;

    Doubly(){
        head = nullptr;
        tail = nullptr;
    }

    void insertBegin(T val){
        Node<T>* tmp = new Node(val);
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
        Node<T>* tmp = new Node(val);
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
        Node<T>* tmp = head;
        while(tmp && tmp->data!=key){
            tmp = tmp->next;
        }
        if(!tmp){
            std::cout<<Color::BG_RED<<"Key not Found!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        Node<T>* dum = new Node(val);
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
        Node<T>* tmp = head;
        while(tmp && tmp->data != key){
            tmp = tmp->next;
        }
        if(!tmp){
            std::cout<<Color::BG_RED<<"Key not Found!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        Node<T>* dum = new Node(val);
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
        Node<T>* tmp = head;
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
        Node<T>* tmp = tail;
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
        Node<T>* tmp = head;
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
        Node<T>* tmp = head;
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
};