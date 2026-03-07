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
};