#include<iostream>
#include "stackengine.hpp"
#include "arrayEngine.hpp"

int main(){
    MyArray arr;
    
    std::cout<<arr.len()<<std::endl;
    arr.display();
    arr.insert_at_first(7);
    arr.insert_at_first(12);
    arr.display();
    arr.insert_at_last(5);
    arr.insert_at_last(4);
    arr.display();
    arr.insert_mid(9,2);
    arr.display();
    arr.insert_mid(8,2);
    arr.display();
    VisuArray vv(arr);
    vv.show();

    SearchArray sa(arr);

    sa.linear_visu(5);
    


    

    return 0;
}