#pragma once

#include "colors.hpp"
#include<iostream>
#include<iomanip>
#include<string>
#include<windows.h>


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

    T getfront(){
        if(isEmp()){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Queue is Empty!!"<<Color::RESET;
            std::cout<<"\n\n";
            return T();
        }
        return arr[front];
    }

    T getrear(){
        if(isEmp()){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Queue is Empty!!"<<Color::RESET;
            std::cout<<"\n\n";
            return T();
        }
        return arr[rear];
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

    void options(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[0]"<<Color::RESET;
        std::cout<<" Push ";
        std::cout<<Color::BMAGENTA<<"[1]"<<Color::RESET;
        std::cout<<" Pop \n";

        std::cout<<Color::BMAGENTA<<"[2]"<<Color::RESET;
        std::cout<<" Front ";
        std::cout<<Color::BMAGENTA<<"[3]"<<Color::RESET;
        std::cout<<" Rear \n";  
        
        std::cout<<Color::BMAGENTA<<"[4]"<<Color::RESET;
        std::cout<<" Visualize \n";

        std::cout<<Color::BMAGENTA<<"[5]"<<Color::RESET;
        std::cout<<Color::BRED<<"EXIT "<<Color::RESET<<"\n";
        std::cout<<"\n\n";
    }

    void menubar(){
        options();
        int choice; 
        std::string ch;
        while(true){
            std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
            std::cin>>ch;
            if(ch.size()==1 && ch[0]>='0' && ch[0]<='5'){
                break;
            }
            std::cout<<"\n\n\n";
            std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
        }

        choice = std::stoi(ch);
        std::cout<<"\n\n";

        if(choice==0){
            std::cout<<Color::BG_YELLOW<<"Pushing value at the End"<<Color::RESET<<"\n\n";
            std::cout<<"Enter value to insert: ";
            T val;
            std::cin>>val;
            push(val);
            menubar();
        }else if(choice==1){
            std::cout<<Color::BG_YELLOW<<"Poping value from the beginning"<<Color::RESET<<"\n\n";
            pop();
            menubar();
        }else if(choice==2){
            std::cout<<"\n\n";
            if(isEmp()){
                std::cout<<Color::BRED<<"Queue is Empty"<<Color::RESET;
                std::cout<<"\n\n";
            }else{
                T el = getfront();
                std::cout<<Color::MAGENTA<<"Front: "<<Color::RESET;
                std::cout<<el<<"\n\n";
            }
            menubar();
        }else if(choice==3){
            std::cout<<"\n\n";
            if(isEmp()){
                std::cout<<Color::BRED<<"Queue is Empty"<<Color::RESET;
                std::cout<<"\n\n";
            }else{
                T el = getrear();
                std::cout<<Color::MAGENTA<<"Rear: "<<Color::RESET;
                std::cout<<el<<"\n\n";
            }
            menubar();
        }else if(choice==4){
            std::cout<<"\n\n";
            std::cout<<Color::BG_YELLOW<<"VISUALIZER"<<Color::RESET<<" :\n";
            visualize();
            std::cout<<"\n\n";
            menubar();
        }else if(choice==5){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Exiting Queue...."<<Color::RESET;
            std::cout<<"\n\n";
            Sleep(2000);
            return;
        }

    }

};