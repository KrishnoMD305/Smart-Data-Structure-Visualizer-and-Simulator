#pragma once
#include<vector> // for storing stack
#include<stdexcept> // exception handling
#include<string>
template<typename T>
class MyStack{
private:
    std::vector<T> data;

public:
    enum{
        MAX_LEN = 10
    };

    void push(const T& val){
        if(data.size() > MAX_LEN){
            throw std::overflow_error("Stack Overflow! Can't push more. ");
        }
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

    friend class VisuStack;

};


class VisuStack{
private:
    MyStack<int> myData;
public:
    VisuStack(MyStack<int> st);
    std::string stackcont(std::string str);
    void visualize();
};