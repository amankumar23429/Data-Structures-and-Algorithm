#include<bits/stdc++.h>
using namespace std;

class Queue{
    int* arr;
    int cs, ms, f, r;

    public:
    Queue(int ds = 5){
        ms = ds;
        cs = 0;
        f = 0;
        r = ms-1;
        arr = new int[ms];
    }

    bool full(){
        return cs == ms;
    }

    bool empty(){
        return cs==0;
    }

    void push(int d){
        if(!full()){
            r = (r+1)%ms;
            arr[r] = d;
            cs++;
        }
    }

    void pop(){
        if(!empty()){
            f = (f+1)%ms;
            cs--;
        }
    }

    int front(){
        if(!empty()){
            return arr[f];
        }
    }

    ~Queue(){
        if(arr!=NULL){
            delete [] arr;
            arr = NULL;
        }
    }
};

int main(){
    Queue q(7);
    for(int i = 1; i<=6; i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(7);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    //cout<<q.front();
    return 0;
}