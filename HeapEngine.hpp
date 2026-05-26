#pragma once

#include<iostream>
#include<vector>
#include "colors.hpp"

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
    }
    void insertMin(T val){
        heap.push_back(val);
        heapifyUMin(heap.size()-1);
    }

    void remove(bool isMax){
        if(heap.empty()){
            std::cout<<"Heap is empty"<<"\n";
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
            std::cout<<"Heap is Empty"<<"\n";
            return;
        }
        printtree();
        std::cout<<"\n\n";
    }

    void optionsMM(){
        std::cout<<Color::BG_CYAN<<"Choose one to continue..."<<Color::RESET<<"\n\n";
        
    }
};
