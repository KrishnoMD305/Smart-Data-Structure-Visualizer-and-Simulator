#pragma once

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

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

        while(!q.empty()){
            T node = q.front();
            q.pop();
            std::cout<<node<<" ";

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
        std::cout<<node<<" ";

        for(T nei : adjacency[node]){
            if(!visited[nei]){
                dfshelper(nei,visited);
            }
        }
    }
    void DFStraverse(T start){
        std::cout<<"\n\n";
        std::unordered_map<T,bool> visited;
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

    

};