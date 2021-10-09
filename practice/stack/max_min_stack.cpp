#include<bits/stdc++.h>
using namespace std;

class Stack{
    vector<int> min_stack;
    vector<int> max_stack;
    vector<int> n_stack;

    public:
    void push(int d){
        if(max_stack.empty() and min_stack.empty()){
            min_stack.push_back(d);
            max_stack.push_back(d);
            n_stack.push_back(d);
        }
        else{
            int curr_max = max(d, max_stack[max_stack.size()-1]);
            int curr_min = min(d, min_stack[min_stack.size()-1]);
            n_stack.push_back(d);
            min_stack.push_back(curr_min);
            max_stack.push_back(curr_max);
        }
    }

    int top(){
        return n_stack[n_stack.size()-1];
    }

    void pop(){
        if(!n_stack.empty()){
            n_stack.pop_back();
            min_stack.pop_back();
            max_stack.pop_back();
        }
        return;
    }

    int get_max(){
        return max_stack[max_stack.size()-1];
    }

    int get_min(){
        return min_stack[min_stack.size()-1];
    }

    void print(){
        cout<<"Stack :- ";
        for(int i = n_stack.size()-1; i>=0; i--){
            cout<<n_stack[i]<<" "; 
        }
        cout<<endl;

        cout<<"MIN Stack :- ";
        for(int i = n_stack.size()-1; i>=0; i--){
            cout<<min_stack[i]<<" "; 
        }
        cout<<endl;

        cout<<"MAX Stack :- ";
        for(int i = n_stack.size()-1; i>=0; i--){
            cout<<max_stack[i]<<" "; 
        }
        cout<<endl;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(3);
    s.pop();
    s.pop();
    s.print();
    cout<<s.get_max();
    return 0;
}