#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKsortedArray(vector<vector<int>> v){
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;
    for(int i = 0; i<v.size(); i++){
        pq.push({v[i][0], {i,0}});
    }

    while(!pq.empty()){
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;
        int y = current.second.second;

        result.push_back(element);

        if(y+1<v[x].size()){
            pq.push({v[x][y+1], {x, y+1}});
        }
    }
    return result;
}

int main(){
    vector<vector<int>> arr{{2,6,12,15}, {1, 3, 14, 20},{3, 5, 8, 10}};
    vector<int> output = mergeKsortedArray(arr);
    for(auto x:output){
        cout<<x<<" ";
    }    
    return 0;
}