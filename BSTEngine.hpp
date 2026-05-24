#pragma once

#include<iostream>
#include "colors.hpp"
#include<string>

template<typename T>
class Noda{
public:
    T data;
    Noda<T>* left;
    Noda<T>* right;

    Noda(T val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class BST{
    Noda<T>* root;

    Noda<T>* findMin(Noda<T>* r) {
        while (r && r->left != nullptr) {
            r = r->left;
        }
        return r;
    }
    Noda<T>* findMax(Noda<T>* r) {
        while (r && r->right != nullptr) {
            r = r->right;
        }
        return r;
    }

    Noda<T>* in_private(Noda<T>* r, T val){
        if(r == nullptr){
            return new Noda<T>(val);
        }
        if (val < r->data) {
            r->left = in_private(r->left, val);
        }
        else if (val > r->data) {
            r->right = in_private(r->right, val);
        }
        return r;
    }

    Noda<T>* remove_pri(Noda<T>* r, T key){
        if(r == nullptr){
            return nullptr;
        }
        if(key < r->data){
            r->left = remove_pri(r->left, key);
        }
        else if(key > r->data){
            r->right = remove_pri(r->right, key);
        }

        else{
            if(r->left == nullptr && r->right == nullptr){
                delete r;
                return nullptr;
            }else if(r->left == nullptr){
                Noda<T>* temp = r->right;
                delete r;
                return temp;
            }else if(r->right == nullptr){
                Noda<T>* temp = r->left;
                delete r;
                return temp;
            }

            Noda<T>* temp = findMin(r->right);
            r->data = temp->data;
            r->right = remove_pri(r->right, temp->data);
        }

        return r;
    }

    void inordr_pri(Noda<T>* r){
        if(r == nullptr){
            return;
        }  
        inordr_pri(r->left);
        std::cout<<r->data<<" ";
        inordr_pri(r->right);
    }
    void preordr_pri(Noda<T>* r){
        if(r==nullptr){
            return;
        }
        std::cout<<r->data<<" ";
        preordr_pri(r->left);
        preordr_pri(r->right);
    }
    void postordr_pri(Noda<T>* r){
        if(r==nullptr){
            return;
        }
        postordr_pri(r->left);
        postordr_pri(r->right);
        std::cout<<r->data<<" ";
    }


    bool src_pri(Noda<T>* r,T key){
        if(r==nullptr){
            return false;
        }
        if(r->data==key){
            return true;
        }else if(key<r->data){
            return src_pri(r->left,key);
        }else{
            return src_pri(r->right, key);
        }
    }


public:
    BST(){
        root = nullptr;
    }
    
    void insert(T val){
        root = in_private(root,val);
    }
    void remove(T key){
        root = remove_pri(root,key);
    }

    bool search(T key){
        return src_pri(root,key);
    }

    void inorder(){
        std::cout<<"\n";
        inordr_pri(root);
        std::cout<<"\n";
    }
    void preorder(){
        std::cout<<"\n";
        preordr_pri(root);
        std::cout<<"\n";
    }
    void postorder(){
        std::cout<<"\n";
        postordr_pri(root);
        std::cout<<"\n";
    }

    void print_tr(Noda<T>* root,std::string ind="",bool isR=true){
        if(!root){
            return;
        }
        print_tr(root->right, ind + (isR ? "        " : "│       "), true);
        std::cout<<ind;
        if(isR){
            std::cout<<"┌───────";
        }else{
            std::cout<<"└───────";
        }
        std::cout<<"["<<root->data<<"]"<<"\n";

        print_tr(root->left, ind + (isR ? "│       " : "        "), false);
    }
    void visualize(){
        if(!root){
            std::cout<<"Tree is empty\n\n";
            return;
        }
        print_tr(root->right,"        ",true);
        std::cout<<"        ["<<root->data<<"]\n";
        print_tr(root->left,"        ",false);
        std::cout<<"\n\n";
    }

};