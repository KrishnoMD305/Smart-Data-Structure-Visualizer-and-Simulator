#pragma once

#include "colors.hpp"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>


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
            prev = cur;
            cur = cur->next;
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

    void deletebegin(){
        if(head==NULL){
            std::cout<<"\n";
            std::cout<<"No elements..";
            std::cout<<"\n";
        }
        Node<T>* tmp = head;
        head = head->next;
        if(head==NULL){
            tail = NULL;
        }
        delete tmp;
        size--;
    }
    void deleteend(){
        if(head==NULL){
            std::cout<<"\n";
            std::cout<<"No elements..";
            std::cout<<"\n";
        }
        if(head==tail){
            delete head;
            head = NULL;
            tail = NULL;
            size--;
            return;
        }
        Node<T>* tmp = head;
        while(tmp->next!=tail){
            tmp = tmp->next;
        }
        delete tail;
        tail = tmp;
        tail->next = NULL;
        size--;
    }
    void deletekey(T key){
        if(head==NULL){
            std::cout<<"\n";
            std::cout<<"No elements..";
            std::cout<<"\n";
        }

        if(head->data==key){
            Node<T>* tmp = head;
            head = head->next;

            if(head==NULL){
                tail = NULL;
            }
            delete tmp;
            size--;
            return;
        }

        Node<T>* prev = head;
        Node<T>* curr = head->next;
        while(curr!=NULL && curr->data!=key){
            prev = curr;
            curr = curr->next;
        }
        if(curr==NULL){
            std::cout<<"\n";
            std::cout<<Color::RED<<"Key Not Found!!"<<Color::RESET;
            std::cout<<"\n";
            return;
        }

        prev->next = curr->next;
        if(curr==tail){
            tail = prev;
        }
        delete curr;
        size--;
    }



    void show(){
        if(head==NULL){
            std::cout<<"\n";
            std::cout<<"No element.";
            std::cout<<"\n";
        }
        Node<T>* tmp = head;
        std::cout<<"\n";
        while(tmp!=NULL){
            std::cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        std::cout<<"\n";
    }


    void visualize(){
        std::cout<<"\n";
        if(!head){
            std::cout<<Color::BG_GREEN<<"  HEAD ──► nullptr"<<Color::RESET<<"\n";
            std::cout<<Color::BG_CYAN<<"  Empty list"<<Color::RESET<<"\n";
            return;
        }

        std::vector<Node<T>*> nodes;
        for(Node<T>* cur = head; cur; cur = cur->next){
            nodes.push_back(cur);
        }

        std::cout << "        ";
        for(auto* n : nodes){
            std::cout<<std::left<<std::setw(28)<<(void*)n;
        }
        std::cout<<"\n";

        std::cout<<Color::BBLUE<<"HEAD ──► "<<Color::RESET;
        for (int i = 0; i < nodes.size(); i++){
            std::cout<<Color::BYELLOW<<"┌────────────────┐"<<Color::RESET;
            if(i+1 < nodes.size()){
                std::cout<<"     ";
            }
        }
        std::cout << "\n";

        std::cout << "         ";
        for(int i = 0; i < nodes.size(); i++){
            std::cout<<Color::BYELLOW<<"|"<<Color::RESET;
            std::cout<<" data: "<<std::setw(6)<<std::left<<nodes[i]->data<<"   ";
            std::cout<<Color::BYELLOW<<"|"<<Color::RESET;
            if(i+1 < nodes.size()){
                std::cout<<Color::BGREEN<<" ──► "<<Color::RESET;
            }
        }
        std::cout<<"\n";

        std::cout << "         ";
        for(int i = 0; i < nodes.size(); i++){
            std::string nextStr;
            if(nodes[i]->next){
                std::ostringstream ss;
                ss<<(void*)nodes[i]->next;
                nextStr = ss.str();
            }else{
                nextStr = "nullptr";
            }
            std::cout<<Color::BYELLOW<<"|"<<Color::RESET;
            std::cout<<" next: "<<std::left<<std::setw(9)<<nextStr;
            std::cout<<Color::BYELLOW<<"|"<<Color::RESET;
            if(i+1 < nodes.size()){
                std::cout<<Color::BRED<<" ──► "<<Color::RESET;
            }
        }
        std::cout<<"\n";

        std::cout<<"         ";
        for(int i = 0; i < nodes.size(); i++){
            std::cout<<Color::BYELLOW<<"└────────────────┘"<<Color::RESET;
            if(i+1 < nodes.size()){
                std::cout<<"     ";
            }
        }
        std::cout<<"\n";

        std::cout<<"         ";
        for(int i = 0; i < nodes.size(); i++){
            if(i+1 == nodes.size()){
                std::cout<<"              ";
                std::cout<<Color::BG_YELLOW<<"▲ TAIL"<<Color::RESET;
            }else{
                std::cout<<"                     ";
            }
        }
        std::cout<<"\n\n";
        std::cout<<Color::BG_BLUE<<"  size: "<<size<<" "<<Color::RESET;
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