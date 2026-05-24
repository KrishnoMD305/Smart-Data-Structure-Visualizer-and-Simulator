#pragma once

#include<iostream>
#include "colors.hpp"
#include<string>

template<typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class BST{
    Node* root;

    Node* findMin(Node* r) {
        while (r && r->left != nullptr) {
            r = r->left;
        }
        return r;
    }
    Node* findMax(Node* r) {
        while (r && r->right != nullptr) {
            r = r->right;
        }
        return r;
    }

    Node* in_private(Node* r, T val){
        if (r == nullptr) {
            return new Node(val);
        }
        if (val < r->data) {
            r->left = insert(r->left, val);
        }
        else if (val > r->data) {
            r->right = insert(r->right, val);
        }
        return r;
    }

    Node* remove_pri(Node* r, T key){
        if(r == nullptr){
            return nullptr;
        }
        if(key < r->data){
            r->left = remove(r->left, key);
        }
        else if(key > r->data){
            r->right = remove(r->right, key);
        }

        else{
            if(r->left == nullptr && r->right == nullptr){
                delete r;
                return nullptr;
            }else if(r->left == nullptr){
                Node* temp = r->right;
                delete r;
                return temp;
            }else if(r->right == nullptr){
                Node* temp = r->left;
                delete r;
                return temp;
            }

            Node* temp = findMin(r->right);
            r->data = temp->data;
            r->right = remove_pri(r->right, temp->data);
        }

        return r;
    }



};