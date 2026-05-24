#include<iostream>
#include "colors.hpp"
#include "stackengine.hpp"
#include "arrayEngine.hpp"
#include "LinkListEngine.hpp"
#include "QueueEngine.hpp"
#include "BSTEngine.hpp"

int main(){
    BST<int> b;
    b.visualize();
    b.insert(6);
    b.insert(10);
    b.insert(5);
    b.visualize();
    b.remove(45);
    b.visualize();
    b.remove(6);
    b.visualize();
    return 0;
}