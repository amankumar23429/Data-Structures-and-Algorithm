#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n;
    vector<int> v;
    
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    cin>>k;
    deque<int> q(k);
    int i;
    for(i=0; i<k; i++){
        while(!q.empty() and v[i] >= v[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    for(; i<n; i++){
        cout<<v[q.front()]<<" ";

        while(!q.empty() and q.front() <= i-k){
            q.pop_front();
        }

        while(!q.empty() and v[i] >= v[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    cout<<v[q.front()];

    return 0;
}