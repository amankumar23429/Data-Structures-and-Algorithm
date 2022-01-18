#include<bits/stdc++.h>
using namespace std;

class Queue{
    list<int> l;
    int cs;
    public:
    
    Queue(){
        cs = 0;
    }

    bool is_empty(){
        return cs==0;
    }

    void push(int data){
        l.push_back(data);
        cs++;
    }

    void pop(){
        if(!is_empty()){
            l.pop_front();
        cs--;
        }
    }

    int front(){
        return l.front();
    }

};

int main(){
    Queue q;
    for(int i = 3; i<=10; i++){
        q.push(i);
    }

    while(!q.is_empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}