#pragma once

#include "colors.hpp"
#include<iostream>
#include<iomanip>
#include<string>


template<typename T>
class Que{
    T arr[10];
    int front,rear;

public:
    Que(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        if(rear==9){
            return true;
        }
        return false;
    }

    bool isEmp(){
        if(front==-1 || front>rear){
            return true;
        }
        return false;
    }

    void push(T x){
        std::cout<<"\n\n";
        if(isFull()){
            std::cout<<Color::BG_RED<<"Queue Overflow!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }

        if(front==-1){
            front = 0;

        }

        rear++;
        arr[rear] = x;
        std::cout<<Color::BG_GREEN<<"Value Inserted at the end successfully."<<Color::RESET;
        std::cout<<"\n\n";
    }

    void pop(){
        std::cout<<"\n\n";
        if(isEmp()){
            std::cout<<Color::BG_RED<<"Queue Underflow!!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }

        front++;
        if(front>rear){
            front = -1;
            rear = -1;
        }
        std::cout<<Color::BG_CYAN<<"Value Deleted from the front successfully."<<Color::RESET;
        std::cout<<"\n\n";
    }

    int len(){
        if(isEmp()){
            return 0;
        }
        return rear-front+1;
    }


    void visualize(){
        if(isEmp()){
            std::cout<<Color::BG_RED<<"Queue is EMPTY"<<Color::RESET<<"\n";
            return;
        }

        int size = len();

        std::cout<<"\n  ";
        for(int i=0; i<size; i++){
            std::cout<<"+--------";
        }
        std::cout<<"+\n";

        std::cout<<"  ";
        for(int i=front; i<=rear; i++){
            std::cout<<"| "<<std::setw(5)<<arr[i]<<"  ";
        }
        std::cout<<"|\n";

        std::cout<<"  ";
        int idx = 0;
        for(int i=front; i<=rear; i++){
            std::cout<<"|  ["<<idx++<<"]   ";
        }
        std::cout<<"|\n";
        std::cout<<"  ";
        for(int i=0; i<size; i++){
            std::cout<<"+--------";
        }
        std::cout<<"+\n";

        std::cout<<"  ";
        std::cout<<"  FRONT";
        for(int i=1; i<size-1; i++){
            std::cout<<"         ";
        }
        if(size>1){
            std::cout<<"          REAR";
        }
        std::cout<<"\n\n";
    }

};