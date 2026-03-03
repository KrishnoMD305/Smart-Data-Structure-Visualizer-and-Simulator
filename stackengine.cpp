#include "stackengine.hpp"

VisuStack::VisuStack(MyStack<int> st):myData(st) {}

std::string VisuStack::stackcont(std::string str, bool istop){
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

void VisuStack::visualize(){
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
            }
        }
    }
}