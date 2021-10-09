#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack{
    T arr[1000];
    int size = 0;
    public:
    Stack(){
        memset(arr, 0, sizeof(arr));
    }

    void push(T d){
        arr[size++] = d;
    }

    void pop(){
        if(size>0){
            size--;
        }
    }
    
    bool empty(){
        if(size==0){
            return true;
        }
        return false;
    }

    T top(){
        if(size>0){
            return arr[size-1];
        }
        //return ;
    }
};

int main(){
    stack<string> s;
    s.push("aman");
    s.push("kumar");
    s.push("Suman");
    //s.push(4);
    s.pop();
    s.pop();
    s.pop();
    //s.pop();
    cout<<s.top()<<endl;
    return 0;
}
