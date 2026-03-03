#include "stackengine.hpp"

VisuStack::VisuStack(MyStack<int> st):myData(st) {}

std::string VisuStack::stackcont(std::string str){
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
    res += '\n';
    res += std::string(18,'-');
    return res;

}

void VisuStack::visualize(){
    if(myData.isempty()){
        char ch = '-';
    }
}