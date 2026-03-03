#pragma once
#include<vector> // for storing stack

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

    
};