#pragma once
#include<vector> // for storing stack
#include<stdexcept> // exception handling
#include<string>
#include<iostream>
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

    int search_el(const T& val){
        for(int i=0; i<len(); i++){
            if(data[i]==val){
                return i;
            }
            return -1;
        }
    }

    friend class VisuStack;

};


class VisuStack{
private:
    MyStack<int> &myData;
public:
    VisuStack(MyStack<int> &st): myData(st) {};
    std::string stackcont(std::string str, bool istop){
        std::string res = "";
        res += '|';
        int l = str.size();
        int total_sp = 16 - l;
        int left_sp = total_sp /2 ;
        int right_sp = total_sp - left_sp;

        res += std::string(left_sp,' ');
        res += str;
        res += std::string(right_sp,' ');
        res += '|';
        if(istop){
            res += "<--- Top Element";
        }
        res += '\n';
        res += std::string(18,'-');
        return res;

    }
    void visualize(){
        if(myData.isempty()){
            std::string ch = "-";
            for(int i=0; i<myData.MAX_LEN; i++){
                std::cout<<stackcont(ch, false)<<"\n";
            }
        }else{
            int size_of_st = myData.len();
            int last_indx = size_of_st - 1;
            bool istop = true;

            for(int i=myData.MAX_LEN - 1; i>=0; i--){
                if(i<=last_indx){
                    std::cout<<stackcont(std::to_string(myData.data[i]), istop)<<"\n";
                    istop = false;
                }else{
                    std::string ch = "-";
                    std::cout<<stackcont(ch, false)<<"\n";
                }
            }
        }
    }
};

class msgs{
public:
    void showCmplxytbl(){
        std::cout<<"push    O(1)   |    len    O(1)\n";
        std::cout<<"pop     O(1)   |  isempty  O(1)\n";
        std::cout<<"top     O(1)   |   search  O(n)\n";
    }

    void show_cmd(){
        
    }
};
