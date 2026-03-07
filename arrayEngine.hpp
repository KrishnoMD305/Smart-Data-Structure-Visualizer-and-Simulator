#pragma once

#include "colors.hpp"
#include<iostream>
#include<string>


class MyArray{
private:
    int MAX_SIZE = 50;
    int data[50];
    int size = 0;
public:
    MyArray(){}
    MyArray(const MyArray &arr){
        size = arr.size;

        for(int i=0; i<size; i++){
            data[i] = arr.data[i];
        }
    }
    void insert_at_last(int val){
        if(size==0){
            data[size] = val;
            size++;
            return;
        }
        data[size] = val;
        size++;
    }
    void insert_at_first(int val){
        if(size==0){
            data[size] = val;
            size++;
            return;
        }
        int temp[size+1];
        temp[0] = val;
        int id = 1;
        for(int i=0; i<size; i++){
            temp[id] = data[i];
            id++;
        }
        size++;
        for(int i=0; i<size; i++){
            data[i] = temp[i];
        }
    }

    void insert_mid(int val, int target){
        int i = size-1;
        while(i>=0){
            data[i+1] = data[i];
            if(i==target){
                break;
            }
            i--;
        }
        data[i] = val;
        size++;
    }

    int len(){
        return size;
    }

    void display(){
        for(int i=0; i<size; i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<"\n";
    }

    void del_at_first(){
        if(size==1){
            size--;
            return;
        }
        int i=1;
        for(;i<size; i++){
            data[i-1] = data[i];
        }
        size--;
    }
    void del_at_last(){
        size--;
    }

    void del_mid(int target){
        for(int i=0; i<size-1; i++){
            if(i>=target){
                data[i] = data[i+1];
            }
        }
        size--;
    }

    friend class VisuArray;
};


class VisuArray{
private:
    MyArray arr;
public:
    VisuArray(const MyArray &tmp): arr(tmp) {}

    void show(){
        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.data[0];

        for(int i=1; i<n; i++){
            max_element = (arr.data[i] > max_element) ? arr.data[i] : max_element;
        }


        std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
        for(int lev = max_element; lev>0; lev--){
            for(int i=0; i<n; i++){
                if(arr.data[i] >= lev){
                    std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                }else{
                    std::cout<<"   ";
                }
                std::cout<<std::string(2, ' ');
            }
            std::cout<<"\n";
        }
        std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
        
    }
};