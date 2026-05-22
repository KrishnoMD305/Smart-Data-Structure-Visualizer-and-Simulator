#pragma once

#include "colors.hpp"
#include<iostream>


template<typename T>
class Node{
public:
    T data;
    Node* next;

    Node(T val){
        data = val;
        next = NULL;
    }
};

template<typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size; 

public:
    LinkedList(): head(NULL),tail(NULL), size(0){}

    void insertatbeggining(T val){
        Node<T>* tmp = new Node<T>(val);
        if(head==NULL){
            head=tmp; tail=tmp;
        }else{
            tmp->next=head;
            head = tmp;
        }
        size++;
    }
    void insertatend(T val){
        Node<T>* tmp = new Node<T>(val);
        if(tail==NULL){
            head = tmp;
            tail = tmp;
        }else{
            tail->next = tmp;
            tail = tmp;
        }
        size++;
    }

    void insertafter(T key,T val){
        Node<T>* tmp = head;
        while(tmp!=NULL && tmp->data!=key){
            tmp = tmp->next;
        }

        if(tmp==NULL){
            std::cout<<"\n";
            std::cout<<Color::RED<<"Key Not Found!!"<<Color::RESET;
            std::cout<<"\n";
            return;
        }

        Node<T>* newnode = new Node<T>(val);
        newnode->next = tmp->next;
        tmp->next = newnode;

        if(tmp==tail){
            tail = newnode;
        }

        size++;
    }

    void insertbefore(T key, T val){
        if(head->data==key){
            insertatbeggining(val);
            return;
        }

        Node<T>* prev = NULL;
        Node<T>* cur = head;

        while(cur != NULL && cur->data != key){
            prev = curr;
            curr = curr->next;
        }

        if(cur == NULL){
            std::cout<<"\n";
            std::cout<<Color::RED<<"Key Not Found!!"<<Color::RESET;
            std::cout<<"\n";
            return;
        }

        Node<T>* tmp = new Node<T>(val);
        prev->next = tmp;
        tmp->next = cur;

        size++;
    }



    void show(){
        Node<T>* tmp = head;
        std::cout<<"\n";
        while(tmp!=NULL){
            std::cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        std::cout<<"\n";
    }

};