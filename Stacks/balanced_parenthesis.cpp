#include<iostream>
#include<stack>
using namespace std;

bool isValidExp(char *c){
    stack<char> s;
    for(int i = 0; c[i]!='\0'; i++){
        char ch = c[i];
        if(ch=='('){
            s.push(ch);
        }
        else if(ch==')'){
            if(s.empty() or s.top()!='('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    char ch[100] = "((a+b)+(c-d+f))";
    cout<<isValidExp(ch);
    return 0;
}