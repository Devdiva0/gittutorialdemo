#include <iostream>
#include <stack>

using namespace std;

int precedence(char op){
    if(op == '+' || op == '-' ) return 1;
    if(op == '*' || op == '/' ) return 2;
    return 0;
}

bool isOperator(char c){
    return( c== '+' || c=='-' || c== '*' || c== '/');
}

string infixToPostfix(string infix){
    stack<char> s;
    string postfix;
    
    for(int i=0;i<infix.length();i++){
        char c=infix[i];
        
        if (isalnum(c)){
            postfix+=c;
        }
        else if(c=='('){
            s.push(c);
        }
        else if (c==')'){
            while(!s.empty()&& s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
        }
        else if(isOperator(c)){
            while(!s.empty()&& precedence(s.top())>=precedence(c)){
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    
    return postfix;
}

int main(){
    string infix="a+b*(c^d-e)^(f+g*h)-i";
    cout<<"Infix to postfix: "<<infixToPostfix(infix)<<endl;
    return 0;
}
