#include<iostream>
#include "stackengine.hpp"

int main(){
    MyStack<int> s1;
    VisuStack v1(s1);
    v1.visualize();
    std::cout<<"***************"<<std::endl;
    s1.push(14);
    v1.visualize();
    s1.push(34);
    s1.push(344);
    s1.push(12894);
    std::cout<<"***************"<<std::endl;
    v1.visualize();

    return 0;
}