#include<iostream>
#include<queue>
using namespace std;


int main(){
    priority_queue<int> pq; // default max heap
    priority_queue<int, vector<int>, greater<int>> pq_min;
    int n;
    cin>>n;

    int num;
    for(int i = 1; i<=n; i++){
        cin>>num;
        pq.push(num);
        pq_min.push(num);
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    while(!pq_min.empty()){
        cout<<pq_min.top()<<" ";
        pq_min.pop();
    }
    return 0;
}