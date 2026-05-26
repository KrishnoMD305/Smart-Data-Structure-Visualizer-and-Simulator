#pragma once

#include<iostream>
#include<vector>
#include "colors.hpp"
#include<windows.h>

template<typename T>
class Heaap{
    std::vector<T> heap;

    void heapifyUMax(int ind){
        while(ind>0){
            int parent = (ind-1)/2;
            if(heap[parent]<heap[ind]){
                std::swap(heap[parent],heap[ind]);
                ind = parent;
            }else{
                break;
            }
        }
    }
    void heapifyUMin(int ind){
        while(ind>0){
            int parent = (ind-1)/2;
            if(heap[parent]>heap[ind]){
                std::swap(heap[parent],heap[ind]);
                ind = parent;
            }else{
                break;
            }
        }
    }
    void heapifyDMax(int ind){
        int len = heap.size();
        while(true){
            int l = 2*ind+1;
            int r = 2*ind+2;
            int bigst = ind;
            if(l<len && heap[l]>heap[bigst]){
                bigst = l;
            }
            if(r<len && heap[r]>heap[bigst]){
                bigst = r;
            }
            if(bigst!=ind){
                std::swap(heap[ind],heap[bigst]);
                ind = bigst;
            }else{
                break;
            }
        }
    }
    void heapifyDMin(int ind){
        int len = heap.size();
        while(true){
            int l = 2*ind+1;
            int r = 2*ind+2;
            int smlst = ind;
            if(l<len && heap[l]<heap[smlst]){
                smlst = l;
            }
            if(r<len && heap[r]<heap[smlst]){
                smlst = r;
            }
            if(smlst!=ind){
                std::swap(heap[ind],heap[smlst]);
                ind = smlst;
            }else{
                break;
            }
        }
    }

public:
    void insertMax(T val){
        heap.push_back(val);
        heapifyUMax(heap.size()-1);
        std::cout<<"\n\n";
        std::cout<<Color::BG_GREEN<<"Value inserted successfully"<<Color::RESET<<"\n\n";
    }
    void insertMin(T val){
        heap.push_back(val);
        heapifyUMin(heap.size()-1);
    }

    void remove(bool isMax){
        if(heap.empty()){
            std::cout<<Color::BRED<<"Heap is empty"<<Color::RESET<<"\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty()){
            if(isMax){
                heapifyDMax(0);
            }else{
                heapifyDMin(0);
            }
        }
        std::cout<<"\n\n";
        std::cout<<Color::BG_RED<<"Root removed successfully"<<Color::RESET<<"\n\n";
    }

    std::vector<T> heapsortasc(){
        std::vector<T> tmp = heap;
        int n = tmp.size();

        for(int i=n/2-1; i>=0; i--){
            int ind = i;
            while(true){
                int l = 2*ind+1;
                int r = 2*ind+2;
                int bigst = ind;
                if(l<n && tmp[l]>tmp[bigst]){
                    bigst = l;
                }
                if(r<n && tmp[r]>tmp[bigst]){
                    bigst = r;
                }
                if(bigst!=ind){
                    std::swap(tmp[ind],tmp[bigst]);
                    ind = bigst;
                }else{
                    break;
                }
            }
        }
        for(int i=n-1; i>0; i--){
            std::swap(tmp[0],tmp[i]);
            int size = i;
            int idx = 0;
            while(true){
                int l = 2*idx+1;
                int r = 2*idx+2;
                int bigst = idx;
                if(l<size && tmp[l]>tmp[bigst]){
                    bigst = l;
                }
                if(r<size && tmp[r]>tmp[bigst]){
                    bigst = r;
                }
                if(bigst!=idx){
                    std::swap(tmp[idx],tmp[bigst]);
                    idx = bigst;
                }else{
                    break;
                }
            }
        }
        return tmp;
    }
    std::vector<T> heapsortdesc(){
        std::vector<T> tmp = heap;
        int n = tmp.size();

        for(int i=n/2-1; i>=0; i--){
            int ind = i;
            while(true){
                int l = 2*ind+1;
                int r = 2*ind+2;
                int smlst = ind;
                if(l<n && tmp[l]<tmp[smlst]){
                    smlst = l;
                }
                if(r<n && tmp[r]<tmp[smlst]){
                    smlst = r;
                }
                if(smlst!=ind){
                    std::swap(tmp[ind],tmp[smlst]);
                    ind = smlst;
                }else{
                    break;
                }
            }
        }
        for(int i=n-1; i>0; i--){
            std::swap(tmp[0],tmp[i]);
            int size = i;
            int idx = 0;
            while(true){
                int l = 2*idx+1;
                int r = 2*idx+2;
                int smlst = idx;
                if(l<size && tmp[l]<tmp[smlst]){
                    smlst = l;
                }
                if(r<size && tmp[r]<tmp[smlst]){
                    smlst = r;
                }
                if(smlst!=idx){
                    std::swap(tmp[idx],tmp[smlst]);
                    idx = smlst;
                }else{
                    break;
                }
            }
        }
        return tmp;
    }

    void printtree(int ind=0,std::string indent="",bool isR=true){
        if(ind>=heap.size()){
            return;
        }
        int rChild = 2*ind+2;
        int lChild = 2*ind+1;
        printtree(rChild,indent+(isR?"        ":"│       "),true);
        std::cout<<indent;
        if(isR){
            std::cout<<"┌───────";
        }else{
            std::cout<<"└───────";
        }
        std::cout<<"["<<heap[ind]<<"]"<<"\n";
        printtree(lChild,indent+(isR?"│       ":"        "),false);
    }
    void visualize(){
        if(heap.empty()){
            std::cout<<Color::BRED<<"Heap is Empty"<<Color::RESET<<"\n";
            return;
        }
        printtree();
        std::cout<<"\n\n";
    }

    void optionsMM(){
        std::cout<<Color::BG_CYAN<<"Choose one to continue..."<<Color::RESET<<"\n\n";
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[1] "<<Color::RESET;
        std::cout<<"Max Heap\n";
        std::cout<<Color::BMAGENTA<<"[2] "<<Color::RESET;
        std::cout<<"Min Heap\n";
        std::cout<<Color::BMAGENTA<<"[3] "<<Color::RESET;
        std::cout<<Color::BRED<<"Exit"<<Color::RESET;
        std::cout<<"\n\n";
    }
    void option(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[0] "<<Color::RESET;
        std::cout<<Color::BBLUE<<"Insert "<<Color::RESET;
        std::cout<<Color::BMAGENTA<<"[1] "<<Color::RESET;
        std::cout<<Color::BBLUE<<"Remove "<<Color::RESET<<"\n";
        std::cout<<Color::BMAGENTA<<"[2] "<<Color::RESET;
        std::cout<<Color::BBLUE<<"Visualization "<<Color::RESET<<"\n";
        std::cout<<Color::BMAGENTA<<"[3] "<<Color::RESET;
        std::cout<<Color::BBLUE<<"Heap Sort "<<Color::RESET<<"\n";
        std::cout<<Color::BMAGENTA<<"[4] "<<Color::RESET;
        std::cout<<Color::BRED<<"Exit "<<Color::RESET<<"\n\n";
    }

    void menuMax(){
        option();
        int choice; 
        std::string ch;
        while(true){
            std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
            std::cin>>ch;
            if(ch.size()==1 && ch[0]>='0' && ch[0]<='4'){
                break;
            }
            std::cout<<"\n\n\n";
            std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
        }

        choice = std::stoi(ch);
        std::cout<<"\n\n";

        if(choice==0){
            std::cout<<Color::BG_YELLOW<<"Value Insertion"<<Color::RESET<<"\n\n";
            std::cout<<Color::BGREEN<<"Enter value to Insert : ";
            T val;
            std::cin>>val;
            insertMax(val);
            menuMax();
        }else if(choice==1){
            std::cout<<Color::BG_YELLOW<<"Root Removal"<<Color::RESET<<"\n\n";
            remove(true);
            menuMax();
        }else if(choice==2){
            std::cout<<Color::BG_YELLOW<<"Heap Visualization"<<Color::RESET<<"\n\n";
            visualize();
            menuMax();
        }else if(choice==3){
            std::cout<<Color::BG_YELLOW<<"Heap Sort"<<Color::RESET<<"\n\n";
            if(heap.empty()){
                std::cout<<Color::BRED<<"Heap is empty"<<Color::RESET<<"\n";
                menuMax();
            }
            std::vector<T> sortedAsc = heapsortasc();
            std::vector<T> sortedDsc = heapsortdesc();
            std::cout<<Color::BYELLOW<<"Ascending : "<<Color::RESET;
            for(T i : sortedAsc){
                std::cout<<Color::MAGENTA<<i<<Color::RESET<<" ";
            }
            std::cout<<"\n\n";
            std::cout<<Color::BYELLOW<<"Descending : "<<Color::RESET;
            for(T i : sortedDsc){
                std::cout<<Color::MAGENTA<<i<<Color::RESET<<" ";
            }
            std::cout<<"\n\n";
            menuMax();
        }else if(choice==4){
            heap.clear();
            std::cout<<"\n\n";
            return;
        }
    }
    void menuMin(){
        option();
        int choice; 
        std::string ch;
        while(true){
            std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
            std::cin>>ch;
            if(ch.size()==1 && ch[0]>='0' && ch[0]<='4'){
                break;
            }
            std::cout<<"\n\n\n";
            std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
        }

        choice = std::stoi(ch);
        std::cout<<"\n\n";

        if(choice==0){
            std::cout<<Color::BG_YELLOW<<"Value Insertion"<<Color::RESET<<"\n\n";
            std::cout<<Color::BGREEN<<"Enter value to Insert : ";
            T val;
            std::cin>>val;
            insertMin(val);
            menuMin();
        }else if(choice==1){
            std::cout<<Color::BG_YELLOW<<"Root Removal"<<Color::RESET<<"\n\n";
            remove(false);
            menuMin();
        }else if(choice==2){
            std::cout<<Color::BG_YELLOW<<"Heap Visualization"<<Color::RESET<<"\n\n";
            visualize();
            menuMin();
        }else if(choice==3){
            std::cout<<Color::BG_YELLOW<<"Heap Sort"<<Color::RESET<<"\n\n";
            if(heap.empty()){
                std::cout<<Color::BRED<<"Heap is empty"<<Color::RESET<<"\n";
                menuMin();
            }
            std::vector<T> sortedAsc = heapsortasc();
            std::vector<T> sortedDsc = heapsortdesc();
            std::cout<<Color::BYELLOW<<"Ascending : "<<Color::RESET;
            for(T i : sortedAsc){
                std::cout<<Color::MAGENTA<<i<<Color::RESET<<" ";
            }
            std::cout<<"\n\n";
            std::cout<<Color::BYELLOW<<"Descending : "<<Color::RESET;
            for(T i : sortedDsc){
                std::cout<<Color::MAGENTA<<i<<Color::RESET<<" ";
            }
            std::cout<<"\n\n";
            menuMin();
        }else if(choice==4){
            heap.clear();
            std::cout<<"\n\n";
            return;
        }
    }

    void menubar(){
        optionsMM();
        int choice; 
        std::string ch;
        while(true){
            std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
            std::cin>>ch;
            if(ch.size()==1 && ch[0]>='1' && ch[0]<='3'){
                break;
            }
            std::cout<<"\n\n\n";
            std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
        }

        choice = std::stoi(ch);
        std::cout<<"\n\n";

        if(choice==1){
            std::cout<<Color::BCYAN<<"Max Heap"<<Color::RESET<<"\n\n";
            menuMax();
            menubar();
        }else if(choice==2){
            std::cout<<Color::BCYAN<<"Min Heap"<<Color::RESET<<"\n\n";
            menuMin();
            menubar();
        }else if(choice==3){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Exiting Heap...."<<Color::RESET;
            std::cout<<"\n\n";
            Sleep(2000);
            return;
        }
    }
};
