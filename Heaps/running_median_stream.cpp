#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> left_heap;
    priority_queue<int, vector<int>, greater<int>> right_heap;
    int d;
    cin>>d;
    left_heap.push(d);
    
    float median = d;
    cout<<"median "<<median<<endl;

    cin>>d;
    while(d!=-1){
        if(d>left_heap.top()){
            if(left_heap.size()>=right_heap.size()){
                right_heap.push(d);
            }
            else{
                left_heap.push(right_heap.top());
                right_heap.pop();
                right_heap.push(d);
            }
        }
        else{
            if(right_heap.size()>=left_heap.size()){
                left_heap.push(d);
            }
            else{
                right_heap.push(left_heap.top());
                left_heap.pop();
                left_heap.push(d);
            }
        }
        if(left_heap.size()>right_heap.size()){
            median = left_heap.top();
        }
        else if(left_heap.size()<right_heap.size()){
            median = right_heap.top();
        }
        else{
            median = (right_heap.top()+left_heap.top())/2.0;
        }
        cout<<"median "<<median<<endl;
        cin>>d;
    }
    return 0;
}