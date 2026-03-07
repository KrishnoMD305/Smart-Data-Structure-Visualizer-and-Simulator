#pragma once

#include "colors.hpp"


class MyArray{
private:
    int MAX_SIZE = 50;
    int data[50];
    int size = 0;
public:
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
};