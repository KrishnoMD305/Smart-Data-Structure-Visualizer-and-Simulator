#pragma once

#include "colors.hpp"
#include<iostream>
#include<string>
#include<windows.h>


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

    int get_el(int i){
        return data[i];
    }

    friend class VisuArray;
    
};


class VisuArray{
private:
    MyArray arr;
public:
    VisuArray(const MyArray &tmp): arr(tmp) {}

    std::string center(int num, int width){
        std::string s = std::to_string(num);
        int left = (width - s.length()) / 2;
        int right = width - s.length() - left;

        return std::string(left,' ') + s + std::string(right,' ');
    }

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
        for(int i=0; i<n; i++){
            std::cout<<center(arr.get_el(i), 3);
            std::cout<<"  ";
        }

        std::cout<<"\n\n";

    }
};


class SearchArray{
public:
    MyArray arr; 
     
    SearchArray(const MyArray &tmp) : arr(tmp){}

    std::string center(int num, int width){
        std::string s = std::to_string(num);
        int left = (width - s.length()) / 2;
        int right = width - s.length() - left;

        return std::string(left,' ') + s + std::string(right,' ');
    }

    void linear_visu(int target){
        bool found = false;
        int length = arr.len();

        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.get_el(0);

        for(int i=1; i<n; i++){
            max_element = (arr.get_el(i) > max_element) ? arr.get_el(i) : max_element;
        }

        for(int idx=0; idx<length; idx++){
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
            for(int lev = max_element; lev>0; lev--){
                for(int i=0; i<n; i++){
                    if(arr.get_el(i) >= lev){
                        if(i==idx){
                            std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                        }else{
                            std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                        }
                    }else{
                        std::cout<<"   ";
                    }
                    std::cout<<std::string(2, ' ');
                }
                std::cout<<"\n";
            }
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
            for(int i=0; i<n; i++){
                if(i==idx){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(i), 3)<<Color::RESET;
                }else{
                    std::cout<<center(arr.get_el(i), 3);
                }
                std::cout<<"  ";
            }

            std::cout<<"\n";

            if(arr.get_el(idx)==target){
                found = true;
            }

            std::cout<<Color::BMAGENTA<<"\nChecking..\n"<<Color::RESET;
            Sleep(2000);
            if(found){
                std::cout<<Color::BG_GREEN<<"FOUND"<<Color::RESET<<"\n";
                std::cout<<"Element at ";
                std::cout<<Color::BOLD<<"Index : "<<idx<<". \n"<<Color::RESET;
                break;
            }else{
                std::cout<<Color::BG_RED<<"NOT FOUND"<<Color::RESET<<"\n";
                std::cout<<"\n\n";
            }
            Sleep(2000);
        }

        std::cout<<"\n\n";

        std::cout<<Color::BCYAN<<Color::BOLD<<"Linear Searching Complete"<<Color::RESET<<"\n\n";

        if(!found){
            std::cout<<Color::BG_RED<<"Element is not presented in the array"<<Color::RESET<<"\n";
        }

        std::cout<<"\n\n";
    }
};