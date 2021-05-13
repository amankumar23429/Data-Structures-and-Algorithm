#include<bits/stdc++.h>

using namespace std;

int join_ropes(int ropes[], int n){
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes+n);
    
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int new_rope = a+b;
        cost += new_rope;
        
        pq.push(new_rope);
    }
    return cost;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<join_ropes(arr, n);
    return 0;
}