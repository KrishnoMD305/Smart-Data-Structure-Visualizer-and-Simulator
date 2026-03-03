#pragma once
#include<vector> // for storing stack
#include<stdexcept> // exception handling

template<typename T>
class MyStack{
private:
    std::vector<T> data;

public:
    void push(const T& val){
        data.push_back(val);
    }

    bool isempty(){
        return data.empty();
    }

    void pop(){
        if(isempty()){
            throw std::underflow_error("Stack Underflow! Can't pop from empty stack.");

        }
        data.pop_back();
    }

    T top(){
        if(isempty()){
            throw std::underflow_error("Empty Stack! No element available.");
        }
        return data.back();
    }

    int len(){
        return data.size();
    }

    void clear(){
        data.clear();
    }


};