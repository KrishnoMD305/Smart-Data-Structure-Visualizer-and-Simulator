#pragma once

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include "colors.hpp"

template<typename T>
class Graphical{
public:
    std::unordered_map<T,std::vector<T>> adjacency;

    void adddirect(T u, T v){
        adjacency[u].push_back(v);
    }
    void addundirected(T u,T v){
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    void printgraph(){
        std::cout<<"\n\n";
        for(auto pair : adjacency){
            T u = pair.first;
            std::cout<<u;
            std::cout<<":";
            std::vector<T> v = pair.second;
            for(auto i : v){
                std::cout<<i<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n\n";
    }

    void BFStraverse(T start){
        std::cout<<"\n\n";
        std::unordered_map<T,bool> visited;
        std::queue<T> q;
        visited[start] = true;
        q.push(start);
        std::cout<<Color::GREEN<<"BFS"<<Color::RESET<<" : ";
        while(!q.empty()){
            T node = q.front();
            q.pop();
            std::cout<<Color::BMAGENTA<<node<<Color::RESET<<" ";

            for(T nei : adjacency[node]){
                if(!visited[nei]){
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }

        std::cout<<"\n\n";
    }

    void dfshelper(T node, std::unordered_map<T,bool>& visited){
        visited[node] = true;
        std::cout<<Color::BMAGENTA<<node<<Color::RESET<<" ";

        for(T nei : adjacency[node]){
            if(!visited[nei]){
                dfshelper(nei,visited);
            }
        }
    }
    void DFStraverse(T start){
        std::cout<<"\n\n";
        std::unordered_map<T,bool> visited;
        std::cout<<Color::GREEN<<"BFS"<<Color::RESET<<" : ";
        dfshelper(start,visited);
        std::cout<<"\n\n";
    }


    bool cycleDFS(T node,std::unordered_map<T,bool> &visited,std::unordered_map<T,bool> &re){
        visited[node] = true;
        re[node] = true;
        for(T nei : adjacency[node]){
            if(!visited[nei] && cycleDFS(nei,visited,re)){
                return true;
            }
            if(re[nei]){
                return true;
            }
        }
        re[node] = false;
        return false;
    }
    bool isCyclic(){
        std::unordered_map<T,bool> visited;
        std::unordered_map<T,bool> re;

        for (auto pair : adjacency) {
            T node = pair.first;
            if(!visited[node]){
                if(cycleDFS(node,visited,re))
                    return true;
            }
        }
        return false;
    }

    void topohelper(T node,std::unordered_map<T,bool> &visited,std::vector<T>& res){
        visited[node] = true;
        for(T nei : adjacency[node]){
            if(!visited[nei]){
                topohelper(nei,visited,res);
            }
        }
        res.push_back(node);
    }
    std::vector<T> topoSort(){
        std::unordered_map<T,bool> visited;
        std::vector<T> res;

        for(auto pair : adjacency){
            T node = pair.first;
            if(!visited[node]){
                topohelper(node,visited,res);
            }
        }
        std::reverse(res.begin(),res.end());
        return res;
    }

    void GraphOptions(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[1] "<<Color::RESET;
        std::cout<<"Directed Graph\n";
        std::cout<<Color::BMAGENTA<<"[2] "<<Color::RESET;
        std::cout<<"UNDirected Graph\n";
        std::cout<<Color::BMAGENTA<<"[3] "<<Color::RESET;
        std::cout<<"Exit";
        std::cout<<"\n\n";
    }

    void options(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[0] "<<Color::RESET;
        std::cout<<"Show\n";
        std::cout<<Color::BMAGENTA<<"[1] "<<Color::RESET;
        std::cout<<"BFSTraverse\n";
        std::cout<<Color::BMAGENTA<<"[2] "<<Color::RESET;
        std::cout<<"DFSTraverse\n";
        std::cout<<Color::BMAGENTA<<"[3] "<<Color::RESET;
        std::cout<<"CycleDetection\n";
        std::cout<<Color::BMAGENTA<<"[4] "<<Color::RESET;
        std::cout<<Color::BRED<<" EXIT "<<Color::RESET<<"\n";
    }

    void optionsDirect(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[0] "<<Color::RESET;
        std::cout<<"Show\n";
        std::cout<<Color::BMAGENTA<<"[1] "<<Color::RESET;
        std::cout<<"BFSTraverse\n";
        std::cout<<Color::BMAGENTA<<"[2] "<<Color::RESET;
        std::cout<<"DFSTraverse\n";
        std::cout<<Color::BMAGENTA<<"[3] "<<Color::RESET;
        std::cout<<"CycleDetection\n";
        std::cout<<Color::BMAGENTA<<"[4] "<<Color::RESET;
        std::cout<<"Topological Sort\n";
        std::cout<<Color::BMAGENTA<<"[5] "<<Color::RESET;
        std::cout<<Color::BRED<<" EXIT "<<Color::RESET<<"\n";
    }

    void directMenu(){
        optionsDirect();
        int choice; 
        std::string ch;
        while(true){
            std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
            std::cin>>ch;
            if(ch.size()==1 && ch[0]>='0' && ch[0]<='5'){
                break;
            }
            std::cout<<"\n\n\n";
            std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
        }

        choice = std::stoi(ch);
        std::cout<<"\n\n";

        if(choice==0){
            std::cout<<Color::BG_GREEN<<"Adjacency List"<<Color::RESET;
            std::cout<<" : \n";
            printgraph();
            std::cout<<"\n\n";
            directMenu();
        }else if(choice==1){
            std::cout<<Color::BG_YELLOW<<"BFS Traversal"<<Color::RESET<<"\n\n";
            T nod; 
            std::cout<<"Enter start node : ";
            std::cin>>nod;
            BFStraverse(nod);
            std::cout<<"\n\n";
            directMenu();
        }else if(choice==2){
            std::cout<<Color::BG_YELLOW<<"DFS Traversal"<<Color::RESET<<"\n\n";
            T nod; 
            std::cout<<"Enter start node : ";
            std::cin>>nod;
            DFStraverse(nod);
            std::cout<<"\n\n";
            directMenu();
        }else if(choice==3){
            std::cout<<Color::BG_YELLOW<<"Cycle Detection"<<Color::RESET<<"\n\n";
            if(isCyclic()){
                std::cout<<Color::BG_GREEN<<"Cycle is Detected"<<Color::RESET<<"\n\n";
            }else{
                std::cout<<Color::RED<<"There is no cycle"<<Color::RESET<<"\n\n";
            }
            directMenu();
        }else if(choice==4){
            std::cout<<Color::BG_YELLOW<<"Topological Sort"<<Color::RESET<<"\n\n";
            if(isCyclic()){
                std::cout<<Color::BG_RED<<"Cycle is Detected"<<Color::RESET<<"\n";
                std::cout<<Color::GREEN<<"Graph should be ACYCLIC for topological sort"<<Color::RESET<<"\n\n";
            }else{
                std::vector<T> sorted = topoSort();
                std::cout<<Color::BBLUE<<"Sorted"<<Color::RESET<<" : ";
                for(T nd : sorted){
                    std::cout<<Color::MAGENTA<<nd<<Color::RESET<<" ";
                }
                std::cout<<"\n\n";
            }
            directMenu();
        }else if(choice==5){
            std::cout<<"\n\n";
            adjacency.clear();
            return;
        }
    }

    void menu(){
        options();
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
            std::cout<<Color::BG_GREEN<<"Adjacency List"<<Color::RESET;
            std::cout<<" : \n";
            printgraph();
            std::cout<<"\n\n";
            menu();
        }else if(choice==1){
            std::cout<<Color::BG_YELLOW<<"BFS Traversal"<<Color::RESET<<"\n\n";
            T nod; 
            std::cout<<"Enter start node : ";
            std::cin>>nod;
            BFStraverse(nod);
            std::cout<<"\n\n";
            menu();
        }else if(choice==2){
            std::cout<<Color::BG_YELLOW<<"DFS Traversal"<<Color::RESET<<"\n\n";
            T nod; 
            std::cout<<"Enter start node : ";
            std::cin>>nod;
            DFStraverse(nod);
            std::cout<<"\n\n";
            menu();
        }else if(choice==3){
            std::cout<<Color::BG_YELLOW<<"Cycle Detection"<<Color::RESET<<"\n\n";
            if(isCyclic()){
                std::cout<<Color::BG_GREEN<<"Cycle is Detected"<<Color::RESET<<"\n\n";
            }else{
                std::cout<<Color::RED<<"There is no cycle"<<Color::RESET<<"\n\n";
            }
            menu();
        }else if(choice==4){
            std::cout<<"\n\n";
            adjacency.clear();
            return;
        }
    }


    void menubar(){
        GraphOptions();
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
            std::cout<<Color::BG_YELLOW<<"Directed Graph Insertion"<<Color::RESET<<"\n\n";
            T nd; int edg;
            std::cout<<"Enter the number of edges :";
            std::cin>>edg;
            std::cout<<"\n\nEnter the edges: \n";
            for(int i=0; i<edg; i++){
                T u,v; std::cin>>u>>v;
                adddirect(u,v);
            }
            std::cout<<"\n"<<Color::BG_GREEN<<"Insertion Complete"<<Color::RESET<<"\n\n";
            directMenu();
            menubar();
        }else if(choice==2){
            std::cout<<Color::BG_YELLOW<<"Undirected Graph Insertion"<<Color::RESET<<"\n\n";
            T nd; int edg;
            std::cout<<"Enter the number of edges :";
            std::cin>>edg;
            std::cout<<"\n\nEnter the edges: \n";
            for(int i=0; i<edg; i++){
                T u,v; std::cin>>u>>v;
                addundirected(u,v);
            }
            std::cout<<"\n"<<Color::BG_GREEN<<"Insertion Complete"<<Color::RESET<<"\n\n";
            menu();
            menubar();
        }else if(choice==3){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Exiting Graph...."<<Color::RESET;
            std::cout<<"\n\n";
            Sleep(2000);
            return;
        }

    }

};