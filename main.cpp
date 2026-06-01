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

    void menu(std::string username){

    }

};

int main(){
    
    return 0;
}