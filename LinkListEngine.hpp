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

