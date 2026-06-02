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
    friend class StackMenu;

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

    void menubar(){
        while(1){
            std::cout<<"Current Stack: \n\n";
            mys.visualize();
            std::cout<<"\n\n";
            text.showCmplxytbl();
            std::cout<<"\n\n";
            text.show_cmd();
            std::cout<<"\n>>> ";

            int choice;
            std::cin>>choice;

            if(choice==1){
                
                int val; 
                std::cin>>val;
                if(myst.len()==myst.MAX_LEN){
                    std::cout<<Color::RED<<"Stack is Full!. Push element is not possible \n"<<Color::RESET;
                    continue;
                }
                myst.push(val);
                std::cout<<"\n";
                std::cout<<Color::GREEN<<"Successfully pushed value\n"<<Color::RESET;
                Operation opi;
                opi.opType = 1;
                opi.opmsg = "Pushed element " + std::to_string(val);
                opHistory.push_back(opi);
            }else if(choice==2){
                if(myst.isempty()){
                    std::cout<<Color::RED<<"Stack is already empty. Pop is not possible \n"<<Color::RESET;
                    continue;
                }
                int topval = myst.top();
                myst.pop();
                std::cout<<"\n";
                std::cout<<Color::RED<<"Successfully poped \n"<<Color::RESET;
                Operation opi;
                opi.opType = 2;
                opi.opmsg = "Poped last element: " + std::to_string(topval);
                opHistory.push_back(opi);
            }else if(choice==3){
                std::cout<<"\n";
                if(myst.isempty()){
                    if(myst.isempty()){
                        std::cout<<Color::RED<<"Stack is empty. There is no top element \n"<<Color::RESET;
                        continue;
                    }
                }
                std::cout<<"Top Element: "<<myst.top()<<"\n";
                Operation opi;
                opi.opType = 3;
                opi.opmsg = "Requested top element.";
                opHistory.push_back(opi);
            }else if(choice==4){
                std::cout<<"\n";
                std::cout<<"Length of the stack: "<<myst.len()<<"\n";
                Operation opi;
                opi.opType = 4;
                opi.opmsg = "Requested size of the stack.";
                opHistory.push_back(opi);
            }else if(choice==5){
                std::cout<<"\n";
                if(myst.isempty()){
                    std::cout<<"Stack is Empty\n";
                }else{
                    std::cout<<"Not Empty.\n";
                }

                Operation opi;
                opi.opType = 5;
                opi.opmsg = "Requested emptiness of the stack.";
                opHistory.push_back(opi);

            }else if(choice==6){
                
                int target; std::cin>>target;
                if(myst.isempty()){
                    std::cout<<Color::RED<<"Stack is empty. Can't Perform Search operation \n"<<Color::RESET;
                    continue;
                }
                std::cout<<"\nSearching Element..";
                Operation opi;
                opi.opType = 6;
                int index = myst.search_el(target);
                if(index==-1){
                    std::cout<<Color::BRED<<"Not Found!"<<Color::RESET<<"\n";
                    opi.opmsg = "Requested searching for a element in stack. Not fount";
                }else{
                    std::cout<<Color::BGREEN<<"Found the element at the index "<<Color::RESET;
                    std::cout<<index<<"\n";
                    opi.opmsg = "Requested searching for a element in stack. Found at the index " + std::to_string(index);
                }
                opHistory.push_back(opi);
            }else if(choice==8){
                std::cout<<"\n\n";
                if(opHistory.empty()){
                    std::cout<<Color::CYAN<<"No history Available\n"<<Color::RESET;
                    continue;
                }
                std::cout<<Color::BBLUE<<"Stack Operation History :- \n\n"<<Color::RESET;
                std::cout<<"Operation performed  |  Message\n";
                for(auto op : opHistory){
                    if(op.opType==1){
                        std::cout<<"Push                 | ";
                    }else if(op.opType==2){
                        std::cout<<"Pop                  | ";
                    }else if(op.opType==3){
                        std::cout<<"Top                  | ";
                    }else if(op.opType==4){
                        std::cout<<"Len                  | ";
                    }else if(op.opType==5){
                        std::cout<<"IsEmpty              | ";
                    }else if(op.opType==6){
                        std::cout<<"Search               | ";
                    }

                    std::cout<<op.opmsg<<"\n";
                }
            }else if(choice==7){
                break;
            }else{
                std::cout<<"\n";
                std::cout<<Color::BRED<<"Invalid Choice!! Try Again\n"<<Color::RESET;
            }

        }
    }


};