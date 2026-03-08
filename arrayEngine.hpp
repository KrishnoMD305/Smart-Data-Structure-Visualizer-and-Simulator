#pragma once

#include "colors.hpp"
#include<iostream>
#include<string>
#include<windows.h>


class MyArray{
private:
    int MAX_SIZE = 50;
    int data[50];
    int size = 0;
public:
    MyArray(){}
    MyArray(const MyArray &arr){
        size = arr.size;

        for(int i=0; i<size; i++){
            data[i] = arr.data[i];
        }
    }
    void insert_at_last(int val){
        if(size==0){
            data[size] = val;
            size++;
            return;
        }
        data[size] = val;
        size++;
    }
    void insert_at_first(int val){
        if(size==0){
            data[size] = val;
            size++;
            return;
        }
        int temp[size+1];
        temp[0] = val;
        int id = 1;
        for(int i=0; i<size; i++){
            temp[id] = data[i];
            id++;
        }
        size++;
        for(int i=0; i<size; i++){
            data[i] = temp[i];
        }
    }

    void insert_mid(int val, int target){
        int i = size-1;
        while(i>=0){
            data[i+1] = data[i];
            if(i==target){
                break;
            }
            i--;
        }
        data[i] = val;
        size++;
    }

    int len(){
        return size;
    }

    void display(){
        for(int i=0; i<size; i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<"\n";
    }

    void del_at_first(){
        if(size==1){
            size--;
            return;
        }
        int i=1;
        for(;i<size; i++){
            data[i-1] = data[i];
        }
        size--;
    }
    void del_at_last(){
        size--;
    }

    void del_mid(int target){
        for(int i=0; i<size-1; i++){
            if(i>=target){
                data[i] = data[i+1];
            }
        }
        size--;
    }

    int get_el(int i){
        return data[i];
    }

    friend class VisuArray;
    friend class SortArray;
    
};


class VisuArray{
private:
    MyArray arr;
public:
    VisuArray(const MyArray &tmp): arr(tmp) {}

    std::string center(int num, int width){
        std::string s = std::to_string(num);
        int left = (width - s.length()) / 2;
        int right = width - s.length() - left;

        return std::string(left,' ') + s + std::string(right,' ');
    }

    void show(){
        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.data[0];

        for(int i=1; i<n; i++){
            max_element = (arr.data[i] > max_element) ? arr.data[i] : max_element;
        }


        std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
        for(int lev = max_element; lev>0; lev--){
            for(int i=0; i<n; i++){
                if(arr.data[i] >= lev){
                    std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                }else{
                    std::cout<<"   ";
                }
                std::cout<<std::string(2, ' ');
            }
            std::cout<<"\n";
        }
        std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
        for(int i=0; i<n; i++){
            std::cout<<center(arr.get_el(i), 3);
            std::cout<<"  ";
        }

        std::cout<<"\n\n";

    }
};


class SearchArray{
public:
    MyArray arr; 
     
    SearchArray(const MyArray &tmp) : arr(tmp){}

    std::string center(int num, int width){
        std::string s = std::to_string(num);
        int left = (width - s.length()) / 2;
        int right = width - s.length() - left;

        return std::string(left,' ') + s + std::string(right,' ');
    }

    void linear_visu(int target){
        bool found = false;
        int length = arr.len();

        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.get_el(0);

        for(int i=1; i<n; i++){
            max_element = (arr.get_el(i) > max_element) ? arr.get_el(i) : max_element;
        }

        for(int idx=0; idx<length; idx++){
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
            for(int lev = max_element; lev>0; lev--){
                for(int i=0; i<n; i++){
                    if(arr.get_el(i) >= lev){
                        if(i==idx){
                            std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                        }else{
                            std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                        }
                    }else{
                        std::cout<<"   ";
                    }
                    std::cout<<std::string(2, ' ');
                }
                std::cout<<"\n";
            }
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
            for(int i=0; i<n; i++){
                if(i==idx){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(i), 3)<<Color::RESET;
                }else{
                    std::cout<<center(arr.get_el(i), 3);
                }
                std::cout<<"  ";
            }

            std::cout<<"\n";

            if(arr.get_el(idx)==target){
                found = true;
            }

            std::cout<<Color::BMAGENTA<<"\nChecking..\n"<<Color::RESET;
            Sleep(2000);
            if(found){
                std::cout<<Color::BG_GREEN<<"FOUND"<<Color::RESET<<"\n";
                std::cout<<"Element at ";
                std::cout<<Color::BOLD<<"Index : "<<idx<<". \n"<<Color::RESET;
                break;
            }else{
                std::cout<<Color::BG_RED<<"NOT FOUND"<<Color::RESET<<"\n";
                std::cout<<"\n\n";
            }
            Sleep(2000);
        }

        std::cout<<"\n\n";

        std::cout<<Color::BCYAN<<Color::BOLD<<"Linear Searching Complete"<<Color::RESET<<"\n\n";

        if(!found){
            std::cout<<Color::BG_RED<<"Element is not presented in the array"<<Color::RESET<<"\n";
        }

        std::cout<<"\n\n";
    }


    void binary_visu(int target){
        bool found = false;
        int length = arr.len();

        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.get_el(0);

        for(int i=1; i<n; i++){
            max_element = (arr.get_el(i) > max_element) ? arr.get_el(i) : max_element;
        }

        int low = 0, high = n-1, mid = -1;
        while(low <= high){
            mid = low + (high-low)/2;
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
            for(int lev = max_element; lev>0; lev--){
                for(int i=0; i<n; i++){
                    if(arr.get_el(i) >= lev){
                        if(i==mid){
                            std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                        }else if(i==low || i==high){
                            std::cout<<Color::BYELLOW<<" █ "<<Color::RESET;
                        }else if(i>low && i<high){
                            std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                        }else{
                            std::cout<<Color::DIM<<" █ "<<Color::RESET;
                        }
                    }else{
                        std::cout<<"   ";
                    }
                    std::cout<<std::string(2, ' ');
                }
                std::cout<<"\n";
            }
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";

            for(int i=0; i<n; i++){
                if(i==mid){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(i), 3)<<Color::RESET;
                }else if(i==low || i==high){
                    std::cout<<Color::BG_YELLOW<<center(arr.get_el(i), 3)<<Color::RESET;
                }else if(i>low && i<high){
                    std::cout<<center(arr.get_el(i), 3);
                }else{
                    std::cout<<Color::DIM<<center(arr.get_el(i), 3)<<Color::RESET;
                }
                std::cout<<"  ";
            }
            std::cout<<"\n";
            for(int i=0; i<n; i++){
                std::string lab = "   ";
                if(i==low && i==mid && i==high){
                    lab = "LMH";
                }else if(i==low && i==mid){
                    lab = "LM ";
                }else if(i==mid && i==high){
                    lab = "MH ";
                }else if(i==low && i==high){
                    lab = "LH ";
                }else if(i==low){
                    lab = " L ";
                }else if(i==mid){
                    lab = " M ";
                }else if(i==high){
                    lab = " H ";
                }
                std::cout<<lab<<"  ";
            }
            std::cout<<"\n\n";

            std::cout<<Color::BG_YELLOW<<"Low="<<low<<" Mid="<<mid<<" High="<<high<<Color::RESET<<"\n\n";

            if(arr.get_el(mid)==target){
                found = true;
            }

            std::cout<<Color::BMAGENTA<<"\nChecking..\n"<<Color::RESET;
            Sleep(4000);

            if(found){
                std::cout<<Color::BG_GREEN<<"FOUND"<<Color::RESET<<"\n";
                std::cout<<"Element at ";
                std::cout<<Color::BOLD<<"Index : "<<mid<<". \n"<<Color::RESET;
                break;
            }else if(arr.get_el(mid) < target){
                low = mid + 1;
                std::cout<<Color::BG_RED<<"NOT FOUND"<<Color::RESET<<"\n";
                std::cout<<Color::BG_BLUE<<"Searching Right Half"<<Color::RESET<<"\n";
                std::cout<<"\n\n";
            }else{
                high = mid - 1;
                std::cout<<Color::BG_RED<<"NOT FOUND"<<Color::RESET<<"\n";
                std::cout<<Color::BG_BLUE<<"Searching left Half"<<Color::RESET<<"\n";
                std::cout<<"\n\n";
            }
            Sleep(2000);

        }

        std::cout<<"\n\n";

        std::cout<<Color::BCYAN<<Color::BOLD<<"Binary Searching Complete"<<Color::RESET<<"\n\n";

        if(!found){
            std::cout<<Color::BG_RED<<"Element is not presented in the array"<<Color::RESET<<"\n";
        }

        std::cout<<"\n\n";
    }


    int linear_search(int target){
        for(int i=0; i<arr.len(); i++){
            if(arr.get_el(i)==target){
                return i;
            }
        }
        return -1;
    }

    int binary_search(int target){
        int mid = -1, low = 0, high = arr.len()-1;

        while(low<=high){
            mid = low + (high-low) / 2;
            if(arr.get_el(mid)==target){
                return mid;
            }else if(arr.get_el(mid)<target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return -1;
    }
};



class SortArray{
public:
    MyArray arr;

    SortArray(const MyArray &tmp) : arr(tmp){}

    std::string center(int num, int width){
        std::string s = std::to_string(num);
        int left = (width - s.length()) / 2;
        int right = width - s.length() - left;

        return std::string(left,' ') + s + std::string(right,' ');
    }

    void bubble_visu(){
        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.get_el(0);

        for(int i=1; i<n; i++){
            max_element = (arr.get_el(i) > max_element) ? arr.get_el(i) : max_element;
        }

        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){

                std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
                for(int lev = max_element; lev>0; lev--){
                    for(int k=0; k<n; k++){
                        if(arr.get_el(k) >= lev){
                            if(k==j || k==j+1){
                                std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                            }else{
                                std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                            }
                        }else{
                            std::cout<<"   ";
                        }
                        std::cout<<std::string(2, ' ');
                    }
                    std::cout<<"\n";
                }
                std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
                for(int k=0; k<n; k++){
                    if(k==j || k==j+1){
                        std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
                    }else{
                        std::cout<<center(arr.get_el(k), 3);
                    }
                    std::cout<<"  ";
                }
                std::cout<<"\n";
                std::cout<<Color::BMAGENTA<<"Comparing "<<arr.get_el(j)<<" and "<<arr.get_el(j+1)<<"."<<Color::RESET<<"\n";
                Sleep(4000);
                if(arr.data[j] > arr.data[j+1]){
                    int t = arr.data[j];
                    arr.data[j] = arr.data[j+1];
                    arr.data[j+1] = t;
                    std::cout<<Color::BOLD<<arr.data[j]<<" is greater than "<<arr.data[j+1]<<". Need swap."<<Color::RESET<<"\n";
                    std::cout<<"\n";
                    Sleep(4000);
                    std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
                    for(int lev = max_element; lev>0; lev--){
                        for(int k=0; k<n; k++){
                            if(arr.get_el(k) >= lev){
                                if(k==j || k==j+1){
                                    std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                                }else{
                                    std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                                }
                            }else{
                                std::cout<<"   ";
                            }
                            std::cout<<std::string(2, ' ');
                        }
                        std::cout<<"\n";
                    }
                    std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
                    for(int k=0; k<n; k++){
                        if(k==j || k==j+1){
                            std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                        }else{
                            std::cout<<center(arr.get_el(k), 3);
                        }
                        std::cout<<"  ";
                    }
                    std::cout<<"\n\n";
                    std::cout<<Color::BG_GREEN<<"Elements Swapped."<<Color::RESET<<"\n\n";
                    Sleep(4000);

                }else{
                    std::cout<<Color::BOLD<<arr.data[j]<<" is lower than "<<arr.data[j+1]<<". Doesn't need swap."<<Color::RESET<<"\n\n";
                    Sleep(4000);
                }

            }

        }

        std::cout<<Color::BGREEN<<"Array Sorting Successful. "<<Color::RESET<<"\n\n";
    }

    void bubble_sort(){
        int n = arr.len();
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(arr.data[j] > arr.data[j+1]){
                    int tmp = arr.data[j];
                    arr.data[j] = arr.data[j+1];
                    arr.data[j+1] = tmp;
                }
            }
        }
    }

    void insertion_sort(){
        int n = arr.len();
        for(int i=1; i<n; i++){
            int key = arr.data[i];
            int j = i - 1;

            while(j>=0 && arr.data[j]>key){
                arr.data[j+1] = arr.data[j];
                j--;
            }

            arr.data[j+1] = key;
        }
    }

    void insertion_visu(){
        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.get_el(0);

        for(int i=1; i<n; i++){
            max_element = (arr.get_el(i) > max_element) ? arr.get_el(i) : max_element;
        }
        for(int i=1; i<n; i++){
            int key = arr.data[i];
            int j = i-1; 

            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
            for(int lev = max_element; lev>0; lev--){
                for(int k=0; k<n; k++){
                    if(arr.get_el(k) >= lev){
                        if(k==i){
                            std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                        }else if(k<i){
                            std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                        }else{
                            std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                        }
                    }else{
                        std::cout<<"   ";
                    }
                    std::cout<<std::string(2, ' ');
                }
                std::cout<<"\n";
            }
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
            for(int k=0; k<n; k++){
                if(k==i){
                    std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
                }else if(k<i){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                }else{
                    std::cout<<center(arr.get_el(k), 3);
                }
                std::cout<<"  ";
            }
            std::cout<<"\n";
            std::cout<<Color::BMAGENTA<<"Picking Key element."<<Color::RESET<<"\n";
            Sleep(4000);
            while(j>=0 && arr.data[j]>key){
                arr.data[j+1] = arr.data[j];
                arr.data[j] = key;
                std::cout<<"\n";
                std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
                for(int lev = max_element; lev>0; lev--){
                    for(int k=0; k<n; k++){
                        if(arr.get_el(k) >= lev){
                            if(k==j || k==j+1){
                                std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                            }else if(k<i){
                                std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                            }else{
                                std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                            }
                        }else{
                            std::cout<<"   ";
                        }
                        std::cout<<std::string(2, ' ');
                    }
                    std::cout<<"\n";
                }
                std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
                for(int k=0; k<n; k++){
                    if(k==j || k==j+1){
                        std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
                    }else if(k<i){
                        std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                    }else{
                        std::cout<<center(arr.get_el(k), 3);
                    }
                    std::cout<<"  ";
                }
                std::cout<<"\n";
                std::cout<<Color::BOLD<<arr.data[j]<<" > "<<arr.data[j+1]<<". Shifting Right. "<<Color::RESET<<"\n";
                Sleep(4000);
                j--;
            }
            std::cout<<"\n";
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
            for(int lev = max_element; lev>0; lev--){
                for(int k=0; k<n; k++){
                    if(arr.get_el(k) >= lev){
                        if(k==j+1){
                            std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                        }else if(k<i){
                            std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                        }else{
                            std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                        }
                    }else{
                        std::cout<<"   ";
                    }
                    std::cout<<std::string(2, ' ');
                }
                std::cout<<"\n";
            }
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
            for(int k=0; k<n; k++){
                if(k<=i){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                }else{
                    std::cout<<center(arr.get_el(k), 3);
                }
                std::cout<<"  ";
            }
            std::cout<<"\n";
            std::cout<<Color::BCYAN<<"Key "<<key<<" placed at index "<<j+1<<". "<<Color::RESET<<"\n\n";
            Sleep(4000);
        }

        std::cout<<Color::BGREEN<<"Array Sorting Successful. "<<Color::RESET<<"\n\n";
    }

    void selection_visu(){
        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.get_el(0);

        for(int i=1; i<n; i++){
            max_element = (arr.get_el(i) > max_element) ? arr.get_el(i) : max_element;
        }
        for(int i=0; i<n-1; i++){
            int mini = i;
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
            for(int lev = max_element; lev>0; lev--){
                for(int k=0; k<n; k++){
                    if(arr.get_el(k) >= lev){
                        if(k==i){
                            std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                        }else if(k<i){
                            std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                        }else{
                            std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                        }
                    }else{
                        std::cout<<"   ";
                    }
                    std::cout<<std::string(2, ' ');
                }
                std::cout<<"\n";
            }
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
            for(int k=0; k<n; k++){
                if(k==i){
                    std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
                }else if(k<i){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                }else{
                    std::cout<<center(arr.get_el(k), 3);
                }
                std::cout<<"  ";
            }
            std::cout<<"\n";
            std::cout<<Color::BMAGENTA<<"Finding minimum element from index "<<i<<". "<<Color::RESET<<"\n";
            Sleep(4000);
            for(int j=i+1; j<n; j++){
                if(arr.data[j] < arr.data[mini]){
                    mini = j;
                }
                std::cout<<"\n";
                std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
                for(int lev = max_element; lev>0; lev--){
                    for(int k=0; k<n; k++){
                        if(arr.get_el(k) >= lev){
                            if(k==mini){
                                std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                            }else if(k==j){
                                std::cout<<Color::BG_BLUE<<" █ "<<Color::RESET;
                            }else if(k<i){
                                std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                            }else{
                                std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                            }
                        }else{
                            std::cout<<"   ";
                        }
                        std::cout<<std::string(2, ' ');
                    }
                    std::cout<<"\n";
                }
                std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
                for(int k=0; k<n; k++){
                    if(k==mini){
                        std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
                    }else if(k==j){
                        std::cout<<Color::BCYAN<<center(arr.get_el(k), 3)<<Color::RESET;
                    }else if(k<i){
                        std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                    }else{
                        std::cout<<center(arr.get_el(k), 3);
                    }
                    std::cout<<"  ";
                }
                std::cout<<"\n";
                std::cout<<Color::BOLD<<"Comparing "<<arr.data[j]<<" with current minimum "<<arr.data[mini]<<". "<<Color::RESET<<"\n";
                Sleep(4000);
            }

            if(arr.data[mini]==arr.data[i]){
                std::cout<<Color::BG_RED<<"No minimum."<<Color::RESET<<"\n";
                std::cout<<Color::BOLD<<"Doesn't need to be swapped."<<Color::RESET<<"\n\n";
                Sleep(4000);
                continue;
            }
            int tmp = arr.data[mini];
            arr.data[mini] = arr.data[i];
            arr.data[i] = tmp;
            std::cout<<"\n";
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
            for(int lev = max_element; lev>0; lev--){
                for(int k=0; k<n; k++){
                    if(arr.get_el(k) >= lev){
                        if(k==i){
                            std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                        }else if(k<i){
                            std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                        }else{
                            std::cout<<Color::BLUE<<" █ "<<Color::RESET;
                        }
                    }else{
                        std::cout<<"   ";
                    }
                    std::cout<<std::string(2, ' ');
                }
                std::cout<<"\n";
            }
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n";
            for(int k=0; k<n; k++){
                if(k<=i){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                }else{
                    std::cout<<center(arr.get_el(k), 3);
                }
                std::cout<<"  ";
            }
            std::cout<<"\n";
            std::cout<<Color::BG_GREEN<<"Minimam element "<<arr.data[i]<<" swapped to index "<<i<<". "<<Color::RESET<<"\n\n";
            Sleep(4000);
        }

        std::cout<<Color::BGREEN<<"Array Sorting Successful. "<<Color::RESET<<"\n\n";

    }

    void selection_sort(){
        int n = arr.len();
        for(int i=0; i<n-1; i++){
            int mini = i;
            for(int j=i+1; j<n; j++){
                if(arr.data[j]<arr.data[mini]){
                    mini = j;
                }
            }
            int tmp = arr.data[i];
            arr.data[i] = arr.data[mini];
            arr.data[mini] = tmp;
        }
    }

};