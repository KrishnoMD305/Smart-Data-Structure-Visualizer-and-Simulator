#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#include "colors.hpp"
#include<windows.h>

class Evaluation{
    std::string inf;
public:
    bool isOprtr(char ch){
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^'){
            return true;
        }
        return false;
    }
    bool isValid(){
        std::string exp = inf;
        std::stack<char> st;
        bool expOp = true;
        for(int i=0; i<exp.size(); i++){
            char ch = exp[i];
            if(ch==' '){
                continue;
            }
            if(isalnum(ch)){
                if(!expOp){
                    return false;
                }
                expOp = false;
            }else if(ch=='('){
                if(!expOp){
                    return false;
                }
                st.push(ch);
            }else if(ch==')'){
                if(expOp){
                    return false;
                }
                if(st.empty()){
                    return false;
                }
                st.pop();
            }else if(isOprtr(ch)){
                if(expOp){
                    return false;
                }
                expOp = true;
            }else{
                return false;
            }
        }

        if(expOp){
            return false;
        }
        if(!st.empty()){
            return false;
        }
        return true;

    }

    bool isEvaluate(){
        std::string exp = inf;
        if(!isValid()){
            return false;
        }

        for(char ch : exp){
            if(isalpha(ch)){
                return false;
            }
        }
        return true;
    }

    int precedence(char op){
        if(op=='^'){
            return 3;
        }else if(op=='*' || op=='/'){
            return 2;
        }else if(op=='+' || op=='-'){
            return 1;
        }
        return 0;
    }

    std::string postf(){
        std::stack<char> st;
        std::string postfix = "";

        for(int i=0; i<inf.size(); i++){
            char ch = inf[i];
            if(ch == ' ') continue;
            if(isdigit(ch)){
                while(i < inf.size() && isdigit(inf[i])){
                    postfix += inf[i++];
                }
                postfix += ' ';
                i--;
            }else if(isalpha(ch)){
                postfix += ch;
                postfix += ' ';
            }else if(ch=='('){
                st.push(ch);
            }else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    postfix += st.top();
                    postfix += ' ';
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }else if(isOprtr(ch)){
                while(!st.empty() && (precedence(st.top())>=precedence(ch))){
                    postfix += st.top();
                    postfix += ' ';
                    st.pop();
                }
                st.push(ch);
            }
        }

        while(!st.empty()){
            postfix += st.top();
            postfix += ' ';
            st.pop();
        }

        return postfix;
    }

    std::string pref(){
        std::string exp = inf;
        std::reverse(exp.begin(),exp.end());
        for(char &ch : exp){
            if(ch=='('){
                ch = ')';
            }else if(ch==')'){
                ch = '(';
            }
        }

        std::stack<char> st;
        std::string prefix = "";

        for(int i=0; i<exp.size(); i++){
            char ch = exp[i];
            if(ch == ' ') continue;
            if(isdigit(ch)){
                std::string num = "";
                while(i < exp.size() && isdigit(exp[i])){
                    num += exp[i++];
                }
                i--;
                std::reverse(num.begin(), num.end());
                prefix += num;
                prefix += ' ';
            }else if(isalpha(ch)){
                prefix += ch;
                prefix += ' ';
            }else if(ch=='('){
                st.push(ch);
            }else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    prefix += st.top();
                    prefix += ' ';
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }else if(isOprtr(ch)){
                while(!st.empty() && (precedence(st.top())>=precedence(ch))){
                    prefix += st.top();
                    prefix += ' ';
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            prefix += st.top();
            prefix += ' ';
            st.pop();
        }
        std::reverse(prefix.begin(), prefix.end());
        std::string fixed = "";
        std::stringstream ss(prefix);
        std::string tok;
        while(ss >> tok){
            std::reverse(tok.begin(), tok.end());
            fixed += tok + ' ';
        }
        return fixed;
    }

    double operation(double a,double b,char op){
        if(op=='+'){
            return a+b;
        }else if(op=='-'){
            return a-b;
        }else if(op=='*'){
            return a*b;
        }else if(op=='/'){
            return a/b;
        }else if(op=='^'){
            return std::pow(a,b);
        }
        return 0;
    }

    double evalPost(std::string post){
        std::stack<double> st;
        std::stringstream ss(post);
        std::string tok;
        while(ss>>tok){
            if(tok=="+" || tok=="-" || tok=="*" || tok=="/" || tok=="^"){
                double b = st.top(); 
                st.pop();
                double a = st.top();
                st.pop();
                double res = operation(a,b,tok[0]);
                st.push(res);
            }else{
                double num = std::stod(tok);
                st.push(num);
            }
        }
        return st.top();
    }
    double evalPre(std::string pre){
        std::stack<double> st;
        std::stringstream ss(pre);
        std::vector<std::string> token;
        std::string tok;
        while(ss>>tok){
            token.push_back(tok);
        }
        for(int i=token.size()-1; i>=0; i--){
            tok = token[i];
            if(tok=="+" || tok=="-" || tok=="*" || tok=="/" || tok=="^"){
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                double res = operation(a,b,tok[0]);
                st.push(res);
            }else{
                double num = std::stod(tok);
                st.push(num);
            }
        }
        return st.top();
    }

    void option(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[1] "<<Color::RESET;
        std::cout<<Color::BBLUE<<"Convert to Postfix "<<Color::RESET<<"\n";
        std::cout<<Color::BMAGENTA<<"[2] "<<Color::RESET;
        std::cout<<Color::BBLUE<<"Convert to Prefix "<<Color::RESET<<"\n";
        std::cout<<Color::BMAGENTA<<"[3] "<<Color::RESET;
        std::cout<<Color::BRED<<"Exit "<<Color::RESET<<"\n\n";
    }


    void menubar(){
        option();
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
            std::cout<<"\n\n";
            std::cout<<Color::BGREEN<<"Infix To Postfix Conversion"<<Color::RESET;
            std::cout<<"\n\n";
            std::string postfix = postf();
            std::cout<<Color::MAGENTA<<"Postfix : "<<Color::RESET;
            std::cout<<Color::BCYAN<<postfix<<Color::RESET;
            std::cout<<"\n\n";
            if(!isEvaluate()){
                std::cout<<Color::BG_YELLOW<<"Expression is not evaluatable."<<Color::RESET;
                std::cout<<"\n\n";
                menubar();
            }else{
                double res = evalPost(postfix);
                std::cout<<Color::MAGENTA<<"Result : "<<Color::RESET;
                std::cout<<Color::BCYAN<<res<<Color::RESET;
                std::cout<<"\n\n";
                menubar();
            }
        }else if(choice==2){
            std::cout<<"\n\n";
            std::cout<<Color::BGREEN<<"Infix To Pretfix Conversion"<<Color::RESET;
            std::cout<<"\n\n";
            std::string prefix = pref();
            std::cout<<Color::MAGENTA<<"Prefix : "<<Color::RESET;
            std::cout<<Color::BCYAN<<prefix<<Color::RESET;
            std::cout<<"\n\n";
            if(!isEvaluate()){
                std::cout<<Color::BG_YELLOW<<"Expression is not evaluatable."<<Color::RESET;
                std::cout<<"\n\n";
                menubar();
            }else{
                double res = evalPre(prefix);
                std::cout<<Color::MAGENTA<<"Result : "<<Color::RESET;
                std::cout<<Color::BCYAN<<res<<Color::RESET;
                std::cout<<"\n\n";
                menubar();
            }
        }else if(choice==3){
            return;
        }
    }

    void mainoption(){
        std::cout<<"\n\n";
        std::cout<<Color::BMAGENTA<<"[1] "<<Color::RESET;
        std::cout<<Color::BBLUE<<"Enter Infix Expression "<<Color::RESET<<"\n";
        std::cout<<Color::BMAGENTA<<"[2] "<<Color::RESET;
        std::cout<<Color::BRED<<"Exit "<<Color::RESET<<"\n\n";
    }
    void menu(){
        mainoption();
        int choice; 
        std::string ch;
        while(true){
            std::cout<<Color::BBLUE<<"Enter your choice: "<<Color::RESET;
            std::cin>>ch;
            if(ch.size()==1 && ch[0]>='1' && ch[0]<='2'){
                break;
            }
            std::cout<<"\n\n\n";
            std::cout<<Color::BG_RED<<"Invalid Choice!! Try Again."<<Color::RESET<<"\n\n\n";
        }

        choice = std::stoi(ch);
        std::cout<<"\n\n";

        if(choice==1){
            std::cout<<Color::BOLD<<"Enter Infix Expression : "<<Color::RESET;
            std::string str; 
            std::cin.ignore();
            std::getline(std::cin,str);
            inf = str;
            std::cout<<"\n\n";
            if(!isValid()){
                std::cout<<Color::BG_YELLOW<<"Expression is not valid."<<Color::RESET;
                std::cout<<"\n\n";
                menu();
            }else{
                menubar();
                menu();
            }
        }else if(choice==2){
            std::cout<<"\n\n";
            std::cout<<Color::BG_RED<<"Exiting...."<<Color::RESET;
            std::cout<<"\n\n";
            Sleep(2000);
            return;
        }
    }
};
