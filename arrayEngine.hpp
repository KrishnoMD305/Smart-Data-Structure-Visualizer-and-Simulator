#pragma once

#include "colors.hpp"
#include<iostream>
#include<string>
#include<windows.h>

class VisuArray;
class SearchArray;
class SortArray;
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
            std::cout<<"\n\n";
            std::cout<<Color::BGREEN<<"Successfully Inserted."<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        data[size] = val;
        size++;
        std::cout<<"\n\n";
        std::cout<<Color::BGREEN<<"Successfully Inserted."<<Color::RESET;
        std::cout<<"\n\n";
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
        std::cout<<"\n\n";
        std::cout<<Color::BGREEN<<"Successfully Inserted."<<Color::RESET;
        std::cout<<"\n\n";
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
        std::cout<<"\n\n";
        std::cout<<Color::BGREEN<<"Successfully Inserted."<<Color::RESET;
        std::cout<<"\n\n";
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
        if(size==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        if(size==1){
            size--;
            std::cout<<"\n\n";
            std::cout<<Color::BRED<<"Successfully Deleted."<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        int i=1;
        for(;i<size; i++){
            data[i-1] = data[i];
        }
        size--;
        std::cout<<"\n\n";
        std::cout<<Color::BRED<<"Successfully Deleted."<<Color::RESET;
        std::cout<<"\n\n";
    }
    void del_at_last(){
        if(size==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        size--;
        std::cout<<"\n\n";
        std::cout<<Color::BRED<<"Successfully Deleted."<<Color::RESET;
        std::cout<<"\n\n";
    }

    void del_mid(int target){
        if(target>size){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Target is out of the bound"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        if(size==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        for(int i=0; i<size-1; i++){
            if(i>=target){
                data[i] = data[i+1];
            }
        }
        size--;
        std::cout<<"\n\n";
        std::cout<<Color::BRED<<"Successfully Deleted."<<Color::RESET;
        std::cout<<"\n\n";
    }

    int get_el(int i){
        return data[i];
    }

    friend class VisuArray;
    friend class SortArray;
    

};


class VisuArray{
private:
    
public:
    MyArray arr;
    VisuArray(const MyArray &tmp): arr(tmp) {}

    std::string center(int num, int width){
        std::string s = std::to_string(num);
        int left = (width - s.length()) / 2;
        int right = width - s.length() - left;

        return std::string(left,' ') + s + std::string(right,' ');
    }

    void show(){
        int n = arr.len();
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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
        if(n==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
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

    int partition(int low, int high){
        int pivot = arr.data[high];
        int i = low - 1;
        for(int j=low; j<high; j++){
            if(arr.data[j]<=pivot){
                i++;
                int tmp = arr.data[j];
                arr.data[j] = arr.data[i];
                arr.data[i] = tmp;
            }
        }
        int temp = arr.data[i+1];
        arr.data[i+1] = arr.data[high];
        arr.data[high] = temp;
        return i+1;
    }


    void quick_sort(int low, int high){
        if(arr.len()==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        if(low < high){
            int piv = partition(low,high);
            quick_sort(low, piv-1);
            quick_sort(piv+1,high);
        }
    }


    int partition_visu(int low, int high, MyArray &sorted){
        int pivot = arr.data[high];
        int i = low - 1;
        int n = arr.len();
        int num = 5*n - 2;
        int max_element = arr.get_el(0);

        for(int i=1; i<n; i++){
            max_element = (arr.get_el(i) > max_element) ? arr.get_el(i) : max_element;
        }
        std::cout<<"\n";
        std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
        for(int lev = max_element; lev>0; lev--){
            for(int k=0; k<n; k++){
                if(arr.get_el(k) >= lev){
                    if(sorted.data[k]){
                        std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                    }else if(k==high){
                        std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                    }else if(k>low || k<high){
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
            if(sorted.data[k]){
                std::cout<<Color::BGREEN<<center(arr.get_el(k), 3)<<Color::RESET;
            }else if(k==high){
                std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
            }else if(k>low || k<high){
                std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
            }else{
                std::cout<<center(arr.get_el(k), 3);
            }
            std::cout<<"  ";
        }
        std::cout<<"\n";
        std::cout<<Color::BG_YELLOW<<"Pvot selected: "<<pivot<<" at index "<<high<<Color::RESET<<"\n";
        Sleep(4000);

        for(int j=low; j<high; j++){
            std::cout<<"\n";
            std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
            for(int lev = max_element; lev>0; lev--){
                for(int k=0; k<n; k++){
                    if(arr.get_el(k) >= lev){
                        if(sorted.data[k]){
                            std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                        }else if(k==high){
                            std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                        }else if(k==i){
                            std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                        }else if(k==j){
                            std::cout<<Color::BG_CYAN<<" █ "<<Color::RESET;
                        }else if(k>low || k<high){
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
                if(sorted.data[k]){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                }else if(k==high){
                    std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
                }else if(k==i){
                    std::cout<<Color::BGREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                }else if(k==j){
                    std::cout<<Color::BCYAN<<center(arr.get_el(k), 3)<<Color::RESET;
                }else if(k>low || k<high){
                    std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                }else{
                    std::cout<<center(arr.get_el(k), 3);
                }
                std::cout<<"  ";
            }
            std::cout<<"\n";
            std::cout<<Color::BOLD<<"Comparing element: "<<arr.data[j]<<" with pivot: "<<pivot<<". "<<Color::RESET<<"\n";
            Sleep(4000);
            if(arr.data[j] <= pivot){
                i++;
                if(i != j){
                    int tmp = arr.data[i];
                    arr.data[i] = arr.data[j];
                    arr.data[j] = tmp;
                    std::cout<<"\n";
                    std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
                    for(int lev = max_element; lev>0; lev--){
                        for(int k=0; k<n; k++){
                            if(arr.get_el(k) >= lev){
                                if(sorted.data[k]){
                                    std::cout<<Color::BG_GREEN<<" █ "<<Color::RESET;
                                }else if(k==high){
                                    std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                                }else if(k==i){
                                    std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                                }else if(k==j){
                                    std::cout<<Color::BG_CYAN<<" █ "<<Color::RESET;
                                }else if(k>low || k<high){
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
                        if(sorted.data[k]){
                            std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                        }else if(k==high){
                            std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
                        }else if(k==i){
                            std::cout<<Color::BGREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                        }else if(k==j){
                            std::cout<<Color::BCYAN<<center(arr.get_el(k), 3)<<Color::RESET;
                        }else if(k>low || k<high){
                            std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
                        }else{
                            std::cout<<center(arr.get_el(k), 3);
                        }
                        std::cout<<"  ";
                    }
                    std::cout<<"\n";
                    std::cout<<Color::BMAGENTA<<arr.data[j]<<" <= pivot: "<<pivot<<". Swapped "<<arr.data[j]<<" and "<<pivot<<". "<<Color::RESET<<"\n";
                    Sleep(4000);
                }else{
                    std::cout<<Color::BMAGENTA<<"Already in place. No swap is needed. "<<Color::RESET<<"\n";
                    Sleep(3000);
                }
            }else{
                std::cout<<Color::BOLD<<arr.data[j]<<" > pivot: "<<pivot<<". No Swap needed. "<<Color::RESET<<"\n";
                Sleep(3000);
            }
        }
        int temp = arr.data[i+1];
        arr.data[i+1] = arr.data[high];
        arr.data[high] = temp;
        sorted.data[i+1] = 1;
        std::cout<<"\n";
        std::cout<<Color::BG_BLUE<<std::string(num,'-')<<Color::RESET<<"\n\n";
        for(int lev = max_element; lev>0; lev--){
            for(int k=0; k<n; k++){
                if(arr.get_el(k) >= lev){
                    if(sorted.data[k]){
                        std::cout<<Color::BGREEN<<" █ "<<Color::RESET;
                    }else if(k==i+1){
                        std::cout<<Color::BG_YELLOW<<" █ "<<Color::RESET;
                    }else if(k>low || k<high){
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
            if(sorted.data[k]){
                std::cout<<Color::BGREEN<<center(arr.get_el(k), 3)<<Color::RESET;
            }else if(k==i+1){
                std::cout<<Color::BG_YELLOW<<center(arr.get_el(k), 3)<<Color::RESET;
            }else if(k>low || k<high){
                std::cout<<Color::BG_GREEN<<center(arr.get_el(k), 3)<<Color::RESET;
            }else{
                std::cout<<center(arr.get_el(k), 3);
            }
            std::cout<<"  ";
        }
        std::cout<<"\n";
        std::cout<<Color::BG_BLUE<<"Pivot "<<arr.data[i+1]<<" is placed at index: "<<i+1<<". "<<Color::RESET<<"\n\n";
        Sleep(4000);
        return i+1;
    }

    void quick_helper(int low, int high, MyArray &sorted){
        if(low<high){
            int pivt = partition_visu(low,high,sorted);
            quick_helper(low,pivt-1,sorted);
            quick_helper(pivt+1,high,sorted);
        }else if(low==high){
            sorted.data[low] = 1;
        }

    }

    void quick_visu(){
        if(arr.len()==0){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Array is Empty.!"<<Color::RESET;
            std::cout<<"\n\n";
            return;
        }
        MyArray sorted;
        for(int i=0; i<arr.len(); i++){
            sorted.insert_at_last(0);
        }

        int n = arr.len();
        quick_helper(0,n-1,sorted);
        std::cout<<Color::BGREEN<<"Array Sorting Successful. "<<Color::RESET<<"\n\n";

    }


    void merge(MyArray &arr, int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1], R[n2];
        for(int i=0; i<n1; i++){
            L[i] = arr.data[left + i];
        }
        for(int i=0; i<n2; i++){
            R[i] = arr.data[mid+i+1];
        }
        int i=0, j=0, k=left;
        while(i<n1 && j<n2){
            if(L[i] <= R[j]){
                arr.data[k] = L[i];
                i++;
            }else{
                arr.data[k] = R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr.data[k] = L[i];
            k++;
            i++;
        }
        while(j<n2){
            arr.data[k] = R[j];
            k++;
            j++;
        }

    }

    void mergesort_helper(MyArray &arr, int left, int right){
        if(left < right){
            int mid = left + (right-left)/2;
            mergesort_helper(arr,left,mid);
            mergesort_helper(arr,mid+1,right);
            merge(arr,left,mid,right);
        }
    }

    void merge_sort(){
        int left = 0, right = arr.len()-1;
        mergesort_helper(arr,left,right);
    }

};



class MenuEngine{
public:
    MyArray arr; 
    void arrayOptions(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[0]"<<Color::RESET;
        std::cout<<"Insert at Last ";
        std::cout<<Color::BMAGENTA<<"[1]"<<Color::RESET;
        std::cout<<"Insert at First ";
        std::cout<<Color::BMAGENTA<<"[2]"<<Color::RESET;
        std::cout<<"Insert at Specific Position \n";

        std::cout<<Color::BMAGENTA<<"[3]"<<Color::RESET;
        std::cout<<"Delete from Last ";
        std::cout<<Color::BMAGENTA<<"[4]"<<Color::RESET;
        std::cout<<"Delete from First ";
        std::cout<<Color::BMAGENTA<<"[5]"<<Color::RESET;
        std::cout<<"Delete from Specific Position \n";

        std::cout<<Color::BMAGENTA<<"[6]"<<Color::RESET;
        std::cout<<"Visualization ";
        std::cout<<Color::BMAGENTA<<"[7]"<<Color::RESET;
        std::cout<<"Searching ";
        std::cout<<Color::BMAGENTA<<"[8]"<<Color::RESET;
        std::cout<<"Sorting \n";

        std::cout<<Color::BMAGENTA<<"[9]"<<Color::RESET;
        std::cout<<Color::BRED<<" EXIT "<<Color::RESET;
        std::cout<<"\n\n";
    }
    void sortingOptions(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[0]"<<Color::RESET;
        std::cout<<"Bubble Sort ";
        std::cout<<Color::BMAGENTA<<"[1]"<<Color::RESET;
        std::cout<<"Bubble Sort Visualization\n";

        std::cout<<Color::BMAGENTA<<"[2]"<<Color::RESET;
        std::cout<<"Insertion Sort ";
        std::cout<<Color::BMAGENTA<<"[3]"<<Color::RESET;
        std::cout<<"Insertion Sort Visualization\n";

        std::cout<<Color::BMAGENTA<<"[4]"<<Color::RESET;
        std::cout<<"Selection Sort ";
        std::cout<<Color::BMAGENTA<<"[5]"<<Color::RESET;
        std::cout<<"Selection Sort Visualization\n";

        std::cout<<Color::BMAGENTA<<"[6]"<<Color::RESET;
        std::cout<<"Quick Sort ";
        std::cout<<Color::BMAGENTA<<"[7]"<<Color::RESET;
        std::cout<<"Quick Sort Visualization\n";

        std::cout<<Color::BMAGENTA<<"[8]"<<Color::RESET;
        std::cout<<"Merge Sort\n";

        std::cout<<Color::BMAGENTA<<"[9]"<<Color::RESET;
        std::cout<<Color::BRED<<" EXIT "<<Color::RESET;
        std::cout<<"\n\n";
    }

    void sortingMenubar(){
        std::cout<<Color::BG_YELLOW<<"Array Sorting"<<Color::RESET<<"\n\n";
        while(1){
            sortingOptions();
            int choice; 
            std::string ch;
            while(true){
                std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
                std::cin>>ch;
                if(ch.size()==1 && ch[0]>='0' && ch[0]<='9'){
                    break;
                }
                std::cout<<"\n\n\n";
                std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
            }

            choice = std::stoi(ch);
            std::cout<<"\n\n";

            if(choice==0){
                std::cout<<Color::BG_YELLOW<<"Bubble Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                sr->bubble_sort();
                std::cout<<"Sorted : ";
                int n = tmp.len();
                for(int i=0; i<n; i++){
                    std::cout<<Color::BCYAN<<tmp.get_el(i)<<" "<<Color::RESET;
                }
                delete sr; 
                std::cout<<"\n\n";
            }else if(choice==1){
                std::cout<<Color::BG_YELLOW<<"Bubble Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                sr->bubble_visu();
                std::cout<<"\n\n";
                delete sr;
            }else if(choice==2){
                std::cout<<Color::BG_YELLOW<<"Insertion Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                sr->insertion_sort();
                std::cout<<"Sorted : ";
                int n = tmp.len();
                for(int i=0; i<n; i++){
                    std::cout<<Color::BCYAN<<tmp.get_el(i)<<" "<<Color::RESET;
                }
                delete sr;
                std::cout<<"\n\n";
            }else if(choice==3){
                std::cout<<Color::BG_YELLOW<<"Insertion Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                sr->insertion_visu();
                delete sr;
                std::cout<<"\n\n";
            }else if(choice==4){
                std::cout<<Color::BG_YELLOW<<"Selection Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                sr->selection_sort();
                std::cout<<"Sorted : ";
                int n = tmp.len();
                for(int i=0; i<n; i++){
                    std::cout<<Color::BCYAN<<tmp.get_el(i)<<" "<<Color::RESET;
                }
                delete sr;
                std::cout<<"\n\n";
            }else if(choice==5){
                std::cout<<Color::BG_YELLOW<<"Selection Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                sr->selection_visu();
                delete sr;
                std::cout<<"\n\n";
            }else if(choice==6){
                std::cout<<Color::BG_YELLOW<<"Quick Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                int n = tmp.len();
                sr->quick_sort(0,n); 
                std::cout<<"Sorted : ";
                for(int i=0; i<n; i++){
                    std::cout<<Color::BCYAN<<tmp.get_el(i)<<" "<<Color::RESET;
                }
                delete sr;
                std::cout<<"\n\n";
            }else if(choice==7){
                std::cout<<Color::BG_YELLOW<<"Quick Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                sr->quick_visu();
                delete sr;
                std::cout<<"\n\n";
            }else if(choice==8){
                std::cout<<Color::BG_YELLOW<<"Merge Sorting"<<Color::RESET<<"\n\n";
                MyArray tmp(arr);
                SortArray *sr = new SortArray(tmp);
                int n = tmp.len();
                sr->merge_sort(); 
                std::cout<<"Sorted : ";
                for(int i=0; i<n; i++){
                    std::cout<<Color::BCYAN<<tmp.get_el(i)<<" "<<Color::RESET;
                }
                delete sr;
                std::cout<<"\n\n";
            }else if(choice==9){
                std::cout<<"\n\n";
                std::cout<<"\n\n";
                Sleep(2000);
                break;
            }
        }
    }

    void searchingOptions(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[1]"<<Color::RESET;
        std::cout<<"Linear Search\n";
        std::cout<<Color::BMAGENTA<<"[2]"<<Color::RESET;
        std::cout<<"Linear Search Visualization\n";
        std::cout<<Color::BMAGENTA<<"[3]"<<Color::RESET;
        std::cout<<"Linear Search\n";
        std::cout<<Color::BMAGENTA<<"[4]"<<Color::RESET;
        std::cout<<"Linear Search Visualization\n";
        std::cout<<Color::BMAGENTA<<"[5]"<<Color::RESET;
        std::cout<<Color::BRED<<" EXIT "<<Color::RESET;
        std::cout<<"\n\n";
    }

    void searchingmenubar(){
        std::cout<<Color::BG_YELLOW<<"Array Searching"<<Color::RESET<<"\n\n";
        while(1){
            searchingOptions();
            int choice; 
            std::string ch;
            while(true){
                std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
                std::cin>>ch;
                if(ch.size()==1 && ch[0]>='1' && ch[0]<='5'){
                    break;
                }
                std::cout<<"\n\n\n";
                std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
            }

            choice = std::stoi(ch);
            std::cout<<"\n\n";

            if(choice==1){
                std::cout<<Color::BG_YELLOW<<"Linear Search"<<Color::RESET<<"\n\n";
                std::cout<<"Enter value to search: ";
                int target;
                std::cin>>target;
                SearchArray *ss = new SearchArray(arr);
                int pos = ss->linear_search(target);
                if(pos==-1){
                    std::cout<<"\n\n";
                    std::cout<<Color::BRED<<"Value didn't Found!!"<<Color::RESET;
                    std::cout<<"\n\n";
                }else{
                    std::cout<<"\n\n";
                    std::cout<<Color::BGREEN<<"Value found at position "<<pos<<"."<<Color::RESET;
                    std::cout<<"\n\n";
                }
                delete ss;
            }else if(choice==2){
                std::cout<<Color::BG_YELLOW<<"Linear Search"<<Color::RESET<<"\n\n";
                std::cout<<"Enter value to search: ";
                int target;
                std::cin>>target;
                SearchArray *ss = new SearchArray(arr);
                ss->linear_visu(target);
                delete ss;
            }else if(choice==3){
                std::cout<<Color::BG_YELLOW<<"Binary Search"<<Color::RESET<<"\n\n";
                std::cout<<"Enter value to search: ";
                int target;
                std::cin>>target;
                SearchArray *ss = new SearchArray(arr);
                int pos = ss->binary_search(target);
                if(pos==-1){
                    std::cout<<"\n\n";
                    std::cout<<Color::BRED<<"Value didn't Found!!"<<Color::RESET;
                    std::cout<<"\n\n";
                }else{
                    std::cout<<"\n\n";
                    std::cout<<Color::BGREEN<<"Value found at position "<<pos<<"."<<Color::RESET;
                    std::cout<<"\n\n";
                }
                delete ss;
            }else if(choice==4){
                std::cout<<Color::BG_YELLOW<<"Binary Search"<<Color::RESET<<"\n\n";
                std::cout<<"Enter value to search: ";
                int target;
                std::cin>>target;
                SearchArray *ss = new SearchArray(arr);
                ss->binary_visu(target);
                delete ss;
            }else if(choice==5){
                std::cout<<"\n\n";
                std::cout<<"\n\n";
                Sleep(2000);
                break;
            }
        }
    }


    void menubar(){
        while(1){
            arrayOptions();
            int choice; 
            std::string ch;
            while(true){
                std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
                std::cin>>ch;
                if(ch.size()==1 && ch[0]>='0' && ch[0]<='9'){
                    break;
                }
                std::cout<<"\n\n\n";
                std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
            }

            choice = std::stoi(ch);
            std::cout<<"\n\n";

            if(choice==0){
                std::cout<<Color::BG_YELLOW<<"Value Insertion at Last"<<Color::RESET<<"\n\n";
                std::cout<<"Enter value to insert: ";
                int val;
                std::cin>>val;
                arr.insert_at_last(val);
            }else if(choice==1){
                std::cout<<Color::BG_YELLOW<<"Value Insertion at First"<<Color::RESET<<"\n\n";
                std::cout<<"Enter value to insert: ";
                int val;
                std::cin>>val;
                arr.insert_at_first(val);
            }else if(choice==2){
                std::cout<<Color::BG_YELLOW<<"Value Insertion at Specific Position"<<Color::RESET<<"\n\n";
                std::cout<<"Enter value to insert: ";
                int val;
                std::cin>>val;
                std::cout<<"Enter Target: ";
                int target;
                std::cin>>target;
                arr.insert_mid(val,target);
            }else if(choice==3){
                std::cout<<Color::BG_YELLOW<<"Value Deletion from First"<<Color::RESET<<"\n\n";
                arr.del_at_first();
            }else if(choice==4){
                std::cout<<Color::BG_YELLOW<<"Value Deletion from Last"<<Color::RESET<<"\n\n";
                arr.del_at_last();
            }else if(choice==5){
                std::cout<<Color::BG_YELLOW<<"Value Deletion from Specific Position"<<Color::RESET<<"\n\n";
                std::cout<<"Enter Position: ";
                int pos;
                std::cin>>pos;
                arr.del_mid(pos);
            }else if(choice==6){
                std::cout<<Color::BG_YELLOW<<"Array Visualization"<<Color::RESET<<"\n\n";
                VisuArray *vv = new VisuArray(arr);
                vv->show();
                delete vv;
            }else if(choice==7){
                searchingmenubar();
            }else if(choice==8){
                sortingMenubar();
            }else if(choice==9){
                std::cout<<"\n\n";
                std::cout<<Color::BG_RED<<"Exiting Array...."<<Color::RESET;
                std::cout<<"\n\n";
                Sleep(2000);
                break;
            }
        }
    }


};
