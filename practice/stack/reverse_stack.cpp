#include<bits/stdc++.h>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){
    for(int i = 0; i<n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverse_stack(stack<int> &s1){
    stack<int> s2;
    int n = s1.size();

    for(int i = 0; i<n-1; i++){
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n-i-1);

        s1.push(x);
        transfer(s2, s1, n-i-1);
    }
}

void insertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
    return;
}

void reverse_stack_recursion(stack<int> &s){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverse_stack_recursion(s);
    insertAtBottom(s, x);
}

int main(){
    stack<int> s;
    int n;
    cin>>n;
    int num;
    for(int i = 0; i<n; i++){
        cin>>num;
        s.push(num);
    }

    reverse_stack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}