#include<iostream>
#include "stackengine.hpp"
#include "arrayEngine.hpp"

int main(){
    MyArray arr;
    
    arr.insert_at_first(5);
    arr.insert_at_last(3);
    arr.insert_at_last(1);
    arr.insert_at_last(6);
    arr.insert_at_last(9);

    VisuArray vv(arr);
    vv.show();

    SortArray sa(arr);
    std::cout<<"\n";
    sa.insertion_visu();
    
    


    

    return 0;
}