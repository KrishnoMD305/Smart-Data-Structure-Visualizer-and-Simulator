#include<iostream>
#include "stackengine.hpp"
#include "arrayEngine.hpp"

int main(){
    MyArray arr;
    
    arr.insert_at_first(4);
    arr.insert_at_last(2);
    arr.insert_at_last(9);
    arr.insert_at_last(10);
    arr.insert_at_last(1);

    VisuArray vv(arr);
    vv.show();

    SortArray sa(arr);
    std::cout<<"\n";
    sa.bubble_visu();
    
    


    

    return 0;
}