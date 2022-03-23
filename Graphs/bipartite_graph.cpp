#include<iostream>
#include<vector>
using namespace std;

bool dfs_helper(vector<int> graph[], int node, int* visited, int parent, int color){
    visited[node] = color;
    for(auto nbr:graph[node]){
        if(visited[nbr]==0){
            bool subprob = dfs_helper(graph, nbr, visited, node, 3-color);
            if(subprob==false){
                return false;
            }
        }
        else if(nbr!=parent and visited[nbr]==color){
            return false;
        }
    }
    return true;
}

bool dfs(vector<int> graph[], int n){
    int visited[n] = {0};
    int color = 1;
    bool ans = dfs_helper(graph, 0, visited, -1, color);
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> vertices[n];
    while(m--){
        int x, y;
        cin>>x>>y;
        vertices[x].push_back(y);
        vertices[y].push_back(x);

    }
    if(dfs(vertices, n)){
        cout<<"Yes it is bipartite graph"<<endl;
    }else{
        cout<<"No it is not a bipartite graph"<<endl;
    }
    return 0;
}