#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#include "colors.hpp"

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

        for(char ch : inf){
            if(isalnum(ch)){
                postfix += ch;
            }else if(ch=='('){
                st.push(ch);
            }else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    postfix += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }else if(isOprtr(ch)){
                while(!st.empty() && (precedence(st.top())>=precedence(ch))){
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while(!st.empty()){
            postfix += st.top();
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

        for(char ch : exp){
            if(isalnum(ch)){
                prefix += ch;
            }else if(ch=='('){
                st.push(ch);
            }else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    prefix += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }else if(isOprtr(ch)){
                while(!st.empty() && (precedence(st.top())>=precedence(ch))){
                    prefix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while(!st.empty()){
            prefix += st.top();
            st.pop();
        }
        std::reverse(prefix.begin(),prefix.end());
        return prefix;
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
            }else{
                double num = std::stod(tok);
                st.push(num);
            }
        }
        return st.top();
    }
};
