#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack{
    queue<T> q1, q2;
    public:

    bool empty(){
        return q1.empty();
    }

    void push(T data){
        q1.push(data);
    }

    void pop(){
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    T top(){
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        T num = q1.front();
        q1.pop();
        q2.push(num);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }

    int size(){
        return q1.size();
    }
};

int main(){
    Stack<int> s;
    for(int i = 3; i<=10; i++){
        s.push(i);
    }
    s.pop();
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}