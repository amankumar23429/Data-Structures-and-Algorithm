#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int> graph[], int node, int n){
    vector<int>dist(n+1, INT_MAX);
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    int ans = INT_MAX;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto nbr:graph[curr]){
            if(dist[nbr]==INT_MAX){
                q.push(nbr);
                dist[nbr] = dist[curr]+1;
            }
            else if(dist[nbr]>=dist[curr]){
                ans = min(dist[nbr]+dist[curr]+1, ans);
            }
        }
    }
    return ans;
}

int solve(vector<int> graph[], int n){
    int ans = INT_MAX;
    for(int i = 1; i<=n; i++){
        ans = min(ans, bfs(graph, i, n));
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> graph[n+1];
    while(m--){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans = solve(graph, n);
    if(ans==INT_MAX){
        cout<<"no cycle present";
    }
    else{
        cout<<"shortest length of cycle is "<<ans;
    }
    return 0;
}