#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int f, r, ms, cs;

public:
    Queue(int ds = 5){
        ms = ds;
        arr = new int[ms];
        cs = 0;
        f = 0;
        r = ms-1;
    }

    bool full(){
        return ms==cs;
    }

    bool empty(){
        return cs==0;
    }

    void push(int data){
        if(!full()){
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }

    void pop(){
        if(!empty()){
            f =(f+1)%ms;
            cs--;
        }
    }

    int front(){
        return arr[f];
    }

    ~Queue(){
        if(arr!=NULL){
            delete [] arr;
            arr = NULL;
        }
    }

};

int main(){
    Queue q;
    for(int i = 0; i<6; i++){
        q.push(i);
    }
    q.pop();
    cout<<q.front();
    // for(int i = 0; i<6; i++){
    //     q.push(i);
    // }
    

    return 0;
}