#pragma once
#include<vector> // for storing stack
#include<stdexcept> // exception handling
#include<string>
#include<iostream>
#include "colors.hpp" // color
template<typename T>
class MyStack{
private:
    std::vector<T> data;

public:
    enum{
        MAX_LEN = 10
    };

    void push(const T& val){
        if(data.size() >= MAX_LEN){
            throw std::overflow_error(Color::RED+std::string("Stack Overflow! Can't push more. ")+Color::RESET);
        }
        data.push_back(val);
    }

    bool isempty(){
        return data.empty();
    }

    void pop(){
        if(isempty()){
            throw std::underflow_error(Color::RED+std::string("Stack Underflow! Can't pop from empty stack.")+Color::RESET);

        }
        data.pop_back();
    }

    T top(){
        if(isempty()){
            throw std::underflow_error(Color::RED+std::string("Empty Stack! No element available.")+Color::RESET);
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
            
        }
        return -1;
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
        std::cout<<Color::BLUE<<"push    O(1)   |    len    O(1)\n"<<Color::RESET;
        std::cout<<Color::BLUE<<"pop     O(1)   |  isempty  O(1)\n"<<Color::RESET;
        std::cout<<Color::BLUE<<"top     O(1)   |   search  O(n)\n"<<Color::RESET;
    }

    void show_cmd(){
        std::cout<<Color::MAGENTA<<"push[1 value]   pop[2]   top[3]  len[4]\n"<<Color::RESET;
        std::cout<<Color::MAGENTA<<"isempty[5]    search[6 value]   Exit[7]\n"<<Color::RESET;
        std::cout<<Color::MAGENTA<<"Show history[8]\n"<<Color::RESET;
    }

    void stackvisu(){
        std::cout<<Color::RED<<" --------------------------------"<<Color::RESET<<"\n";
        std::cout<<Color::RED<<"|                                |"<<Color::RESET<<"\n";
        std::cout<<Color::RED<<"| "<<Color::BGREEN<<"Stack Visualizer and Simulator"<<Color::RED<<" |"<<Color::RESET<<"\n";
        std::cout<<Color::RED<<"|                                |"<<Color::RESET<<"\n";
        std::cout<<Color::RED<<" --------------------------------"<<Color::RESET<<"\n";
    }
};


class Operation{
public:
    int opType;
    std::string opmsg;
};


class StackMenu{
public:
    MyStack<int> myst;
    std::vector<Operation> opHistory;
    msgs text;
    VisuStack mys;

    StackMenu(): mys(myst) {}


};