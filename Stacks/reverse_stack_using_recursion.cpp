#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
    // base case
    if(s.empty()){
        s.push(x);
        return;
    }

    // recursive case
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

void reverse_stack(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }
    
    // pop the top element from stack and push it in the bottom of 'reversed smaller stack'
    int x = s.top();
    s.pop();

    reverse_stack(s);
    insertAtBottom(s, x);
}

int main(){
    stack<int> s;
    for(int i = 1; i<5; i++){
        s.push(i);
    }
    
    reverse_stack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}