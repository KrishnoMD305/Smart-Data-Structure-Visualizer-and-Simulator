#include<iostream>
#include "stackengine.hpp"
#include "arrayEngine.hpp"

int main(){
    MyArray arr;
    
    arr.insert_at_first(2);
    arr.insert_at_last(4);
    arr.insert_at_last(5);
    arr.insert_at_last(6);
    arr.insert_at_last(9);
    arr.insert_at_last(11);
    arr.insert_at_last(12);
    arr.insert_at_last(14);
    VisuArray vv(arr);
    vv.show();

    SearchArray sa(arr);

    sa.binary_visu(8);
    


    

    return 0;
}