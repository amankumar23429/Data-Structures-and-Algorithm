#include<iostream>
#include<queue>
using namespace std;

// method 1 in which push operation is O(1) and pop operation is O(N) and top operation is O(N) 
// template<typename T>
// class Stack{
//     queue<T> q1, q2;

// public:
//     void push(T data){
//         q1.push(data);
//     }

//     void pop(){
//         if(q1.empty()){
//             return;
//         }
//         while(q1.size()>1){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         q1.pop();

//         queue<T> temp = q1;
//         q1 = q2;
//         q2 = temp;
//     }
    
//     T top(){
//         while(q1.size()>1){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         T t =  q1.front();

//         q2.push(t);
//         q1.pop();
//         queue<T> temp = q1;
//         q1 = q2;
//         q2 = temp;
//         return t;
//     }

//     int size(){
//         return q1.size() + q2.size();
//     }

//     bool empty(){
//         return q1.size()==0;
//     }
// };

// method 2 in which push operation is O(N) and pop operation is O(1) and top operation is O(1)
template<typename T>
class Stack{
    queue<T> q1, q2;

public:
    void push(T data){
        if(!q1.empty()){
            if(q2.empty()){
                q2.push(data);
            }
            while(q1.size()>0){
                q2.push(q1.front());
                q1.pop();
            }
            queue<T> temp = q1;
            q1 = q2;
            q2 = temp;
        }
        else{
            q1.push(data);
        }      
    }

    void pop(){
        if(q1.empty()){
            return;
        }else{
            q1.pop();
        }
    }
    
    T top(){
        return q1.front();
    }

    int size(){
        return q1.size() + q2.size();
    }

    bool empty(){
        return q1.size()==0;
    }
};


int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}