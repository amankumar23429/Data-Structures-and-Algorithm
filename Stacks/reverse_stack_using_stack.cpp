#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){
    for(int i = 0; i<n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverse_stack(stack<int> &s1){
    //helper stack
    stack<int> s2;
    int n = s1.size();
    for(int i = 0; i<n-1; i++){
        // pick the element from the top which is insert in the bottom in s1
        int x = s1.top();
        s1.pop();

        // transfer n-i-1 elements from stack s1 to s2
        transfer(s1, s2, n-i-1);

        // insert the x in s1
        s1.push(x);

        // tranfer n-i-1 elements from stack s2 to s1
        transfer(s2, s1, n-i-1);
    }
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