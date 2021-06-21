#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> bellman_ford(int V, int src, vector<vector<int>> edges){
    vector<int> dist(V+1, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i<V-1; i++){
        for(auto edge:edges){
            int x = edge[0];
            int y = edge[1];
            int w = edge[2];
            if(dist[x]!=INT_MAX and dist[x] + w < dist[y]){
                dist[y] = dist[x] + w;
            }
        }
    }
    for(auto edge:edges){
        int x = edge[0];
        int y = edge[1];
        int w = edge[2];
        if(dist[x]!=INT_MAX and dist[x] + w < dist[y]){
            cout<<"Negative weight cycle found";
            exit(0);
        }
    }
    return dist;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    int x, y, wt;
    for(int i = 0; i<m; i++){
        cin>>x>>y>>wt;
        edges.push_back({x,y,wt});
    }
    vector<int> distances = bellman_ford(n, 1, edges);
    for(int i = 1; i<=n; i++){
        cout<<"Node"<<i<<" is at distance "<<distances[i];
    }

    return 0;
}