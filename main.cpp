#include<iostream>
#include "colors.hpp"
#include "stackengine.hpp"
#include "arrayEngine.hpp"
#include "LinkListEngine.hpp"
#include "QueueEngine.hpp"
#include "BSTEngine.hpp"

int main(){
    BST<int> b;
    b.insert(50);
    b.insert(30);
    b.insert(70);
    b.insert(10);
    b.insert(40);
    b.insert(60);
    b.insert(80);
    b.insert(5);
    b.insert(20);
    b.insert(40);
    b.insert(35);
    b.visualize();
    b.inorderSimulator();
    return 0;
}