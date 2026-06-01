#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<conio.h>
#include "colors.hpp"
#include "stackengine.hpp"
#include "arrayEngine.hpp"
#include "LinkListEngine.hpp"
#include "QueueEngine.hpp"
#include "BSTEngine.hpp"
#include "GraphEngine.hpp"
#include "HeapEngine.hpp"
#include "Evaluation.hpp"
#include "DoublyLinkListEngine.hpp"

class User{
public:
    std::string email;
    std::string username;
    std::string password;
};
class UserEngine{
private:
    std::vector<User> users;
    void loadUsers(){
        users.clear();
        std::ifstream file("Users.txt");
        std::string ln;
        while(getline(file,ln)){
            std::stringstream ss(ln);
            User u;
            getline(ss,u.email,',');
            getline(ss,u.username,',');
            getline(ss,u.password,',');
            users.push_back(u);
        }
        file.close();
    }
    void saveUser(User u){
        std::ofstream file("Users.txt",std::ios::app);
        file<<u.email<<","<<u.username<<","<<u.password<<std::endl;
        file.close();
    }
    std::string inputPass(){
        std::string pass;
        char ch;
        while(true){
            ch = getch();
            if(ch==13){
                break;
            }else if(ch==8){
                if(!pass.empty()){
                    pass.pop_back();
                    std::cout<<"\b \b";
                }
            }else{
                pass += ch;
                std::cout<<'*';
            }
        }
        std::cout<<std::endl;
        return pass;
    }
    bool usernameExst(std::string username){
        for(auto u : users){
            if(u.username==username){
                return true;
            }
        }
        return false;
    }
    int emcnt(std::string em){
        int cnt = 0;
        for(auto u : users){
            if(u.email==em){
                cnt++;
            }
        }
        return cnt;
    }

public: 
    void signUp(){
        loadUsers();
        User newUser;
        std::cout<<"\n\n";
        std::cout<<Color::BBLUE<<"Signing Up"<<Color::RESET;
        std::cout<<"\n\n";
        while(true){
            std::cout<<Color::BMAGENTA<<"Enter Email : "<<Color::RESET;
            std::cin>>newUser.email;
            if(emcnt(newUser.email)>=3){
                std::cout<<Color::BG_RED<<"This email already created 3 accounts."<<Color::RESET;
                std::cout<<" Please use another email.\n\n";
            }else{
                break;
            }
        }
        while(true){
            std::cout<<Color::BMAGENTA<<"Enter Username : "<<Color::RESET;
            std::cin>>newUser.username;
            if(usernameExst(newUser.username)){
                std::cout<<Color::BG_RED<<"This username already exists."<<Color::RESET;
                std::cout<<" Please enter another username.\n\n";
            }else{
                break;
            }
        }
        while(true){
            std::cout<<Color::BMAGENTA<<"Enter Password : "<<Color::RESET;
            newUser.password = inputPass();
            if(newUser.password.size()<6){
                std::cout<<Color::BRED<<"Password must be at least 6 characters."<<Color::RESET<<"\n\n";
            }else{
                break;
            }
        }
        saveUser(newUser);
        std::cout<<"\n\n";
        std::cout<<Color::BG_GREEN<<"Sign Up Successful."<<Color::RESET;
        std::cout<<"\n\n";
    }
    void signIn(){
        loadUsers();
        std::string input;
        std::string password;
        std::cout<<"\n\n";
        std::cout<<Color::BBLUE<<"Signing In"<<Color::RESET;
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"Enter Email or Username : "<<Color::RESET;
        std::cin>>input;
        User loggUser;
        bool fnd = false;
        for(auto u : users){
            if(u.email==input || u.username==input){
                loggUser = u;
                fnd = true;
                break;
            }
        }
        if(!fnd){
            std::cout<<Color::BRED<<"Email/Username not Found."<<Color::RESET<<"\n\n";
            return;
        }
        std::cout<<Color::BMAGENTA<<"Enter Password : "<<Color::RESET;
        password = inputPass();
        if(password!=loggUser.password){
            std::cout<<Color::BRED<<"Incorrect Password."<<Color::RESET<<"\n\n";
            return;
        }
        std::cout<<"\n\n";
        std::cout<<Color::BG_GREEN<<"Sign In Successful."<<Color::RESET;
        std::cout<<"\n\n";
        menu(loggUser.username);
    }

    void title(){
        std::cout<<Color::BG_YELLOW<<"======================"<<Color::RESET<<std::endl;
        std::cout<<Color::BG_YELLOW<<"|"<<std::endl;
        std::cout<<Color::BCYAN<<"   DS Visualizer    "<<Color::RESET;
        std::cout<<Color::BG_YELLOW<<"|"<<std::endl;
        std::cout<<Color::BG_YELLOW<<"======================"<<Color::RESET<<std::endl;
    }
    void about(){
        std::cout<<"\n\n";
        std::cout<<Color::BGREEN<<"DS Visualizer"<<Color::RESET<<"\n";
        std::cout<<Color::Italic<<"Version: 1.0"<<Color::RESET<<"\n\n";
        std::cout<<Color::BBLUE<<"Developed by: "<<Color::RESET;
        std::cout<<Color::BOLD<<"Krishno Mondol"<<Color::RESET<<"\n";
        std::cout<<"Student, Department of Computer Science and Engineering,\n";
        std::cout<<"Khulna University of Engineering & Technology\n\n";
        std::cout<<Color::BCYAN<<"DS Visualizer is an educational application designed to help students"<<Color::RESET<<"\n";
        std::cout<<Color::BCYAN<<"learn and understand data structures and algorithms visually."<<Color::RESET<<"\n\n";
        std::cout<<Color::BG_YELLOW<<"Technologies Used:"<<Color::RESET<<"\n";
        std::cout<<Color::BRED<<"- C++"<<Color::RESET<<"\n\n";
        std::cout<<"This software was created for learning and academic purposes.\n\n";
        std::cout<<Color::Italic<<"© 2026 DS Visualizer"<<Color::RESET;
        std::cout<<"\n\n";
    }
    void options(){
        std::cout<<Color::BMAGENTA<<"[1]"<<Color::RESET;
        std::cout<<"Sign In   \n";
        std::cout<<Color::BMAGENTA<<"[2]"<<Color::RESET;
        std::cout<<"Sign Up   \n";
        std::cout<<Color::BMAGENTA<<"[3]"<<Color::RESET;
        std::cout<<"About   \n";
        std::cout<<Color::BMAGENTA<<"[4]"<<Color::RESET;
        std::cout<<Color::BRED<<"EXIT "<<Color::RESET<<"\n";
    }
    void operations(){
        std::cout<<Color::BMAGENTA<<"[1]"<<Color::RESET;
        std::cout<<"Array   \n";
        std::cout<<Color::BMAGENTA<<"[2]"<<Color::RESET;
        std::cout<<"Stack   \n";
        std::cout<<Color::BMAGENTA<<"[3]"<<Color::RESET;
        std::cout<<"Queue   \n";
        std::cout<<Color::BMAGENTA<<"[4]"<<Color::RESET;
        std::cout<<"Expression Convertion   \n";
        std::cout<<Color::BMAGENTA<<"[5]"<<Color::RESET;
        std::cout<<"Linked List   \n";
        std::cout<<Color::BMAGENTA<<"[6]"<<Color::RESET;
        std::cout<<"Doubly Linked List   \n";
        std::cout<<Color::BMAGENTA<<"[7]"<<Color::RESET;
        std::cout<<"Graph   \n";
        std::cout<<Color::BMAGENTA<<"[8]"<<Color::RESET;
        std::cout<<"Binary Search Tree   \n";
        std::cout<<Color::BMAGENTA<<"[9]"<<Color::RESET;
        std::cout<<"Heap   \n";
        std::cout<<Color::BMAGENTA<<"[10]"<<Color::RESET;
        std::cout<<Color::BRED<<"Sign Out "<<Color::RESET<<"\n";
    }

    void menu(std::string username){
        std::string name = username;
        std::cout<<"\n\n";
        std::cout<<"Welcome "<<username<<". Your DS visualizer is ready.\n\n";
        operations();
        int choice; 
        std::string ch;
        while(true){
            std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
            std::cin>>ch;
            if(ch.size()==2 && ch[0]>='1' && ch[0]<='10'){
                break;
            }
            std::cout<<"\n\n\n";
            std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
        }

        choice = std::stoi(ch);
        std::cout<<"\n\n";

        if(choice==1){

        }else if(choice==2){
            StackMenu s;
            s.menubar();
            menu(name);
        }else if(choice==3){
            Que<int> q;
            q.menubar();
            menu(name);
        }else if(choice==4){
            Evaluation e;
            e.menubar();
            menu(name);
        }else if(choice==5){
            LinkedList<int> l;
            l.menubar();
            menu(name);
        }else if(choice==6){
            Doubly<int> d;
            d.menu();
            menu(name);
        }else if(choice==7){
            Graphical<int> g;
            g.menubar();
            menu(name);
        }else if(choice==8){
            BST<int> b;
            b.menubar();
            menu(name);
        }else if(choice==9){
            Heaap<int> h;
            h.menubar();
            menu(name);
        }else if(choice==10){
            return;
        }
    }


    void menubar(){

    }
};

int main(){
    
    return 0;
}