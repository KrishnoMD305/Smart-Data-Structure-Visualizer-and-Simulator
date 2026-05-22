#include<iostream>
#include "stackengine.hpp"
#include "arrayEngine.hpp"
#include "LinkListEngine.hpp"

int main(){
    
    LinkedList<int> list;
    list.show();
    list.insertatbeggining(45);
    list.show();
    list.insertatbeggining(34);
    list.show();
    list.insertatend(50);
    list.insertatend(55);
    list.show();
    list.insertbefore(34,30);
    list.show();
    list.insertafter(55,80);
    list.show();
    list.insertafter(34,40);
    list.insertafter(50,54);
    list.show();
    list.insertbefore(34,32);
    list.insertbefore(80,75);
    list.show();
    list.deletebegin();
    list.show();
    list.deleteend();
    list.show();
    list.deletekey(74);
    list.show();
    list.deletekey(50);
    list.show();

    list.visualize();

    return 0;
}