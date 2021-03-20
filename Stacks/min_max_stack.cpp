#include<iostream>
#include<vector>
using namespace std;


class MinMaxStack{
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;

public:
    void push(int data){
        if(stack.empty()){
            stack.push_back(data);
            min_stack.push_back(data);
            max_stack.push_back(data);
        }
        else{
            int curr_min = min(data, min_stack[min_stack.size()-1]);
            int curr_max = max(data, max_stack[max_stack.size()-1]);
            stack.push_back(data);
            min_stack.push_back(curr_min);
            max_stack.push_back(curr_max);
        }
    }

    int get_min(){
        return min_stack[min_stack.size()-1];
    }

    int get_max(){
        return max_stack[max_stack.size()-1];
    }

    int top(){
        return stack[stack.size()-1];
    }

    void pop(){
        stack.pop_back();
        min_stack.pop_back();
        max_stack.pop_back();
    }

    void print(){
        for(int x:stack){
            cout<<x<<" ";
        }
        cout<<endl;

        for(int x:min_stack){
            cout<<x<<" ";
        }
        cout<<endl;

        for(int x:max_stack){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};

int main(){
    MinMaxStack s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);
    s.pop();
    s.print();
    cout<<endl;
    s.pop();
    s.print();
    cout<<endl;
    cout<<s.top()<<endl;
    cout<<s.get_min()<<endl;
    cout<<s.get_max()<<endl;

    return 0;
    
}