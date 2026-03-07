#include<iostream>
#include "stackengine.hpp"
#include "arrayEngine.hpp"

int main(){
    MyArray arr;
    std::cout<<arr.len()<<std::endl;
    arr.display();
    arr.insert_at_first(34);
    arr.insert_at_first(45);
    arr.display();
    arr.insert_at_last(40);
    arr.insert_at_last(50);
    arr.display();
    arr.insert_mid(70,2);
    arr.display();
    arr.insert_mid(80,2);
    arr.display();
    std::cout<<arr.len()<<std::endl;

    arr.del_mid(1);
    std::cout<<arr.len()<<std::endl;
    arr.display();
    arr.del_mid(3);
    std::cout<<arr.len()<<std::endl;
    arr.display();

    return 0;
}