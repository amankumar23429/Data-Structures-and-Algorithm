#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stack){
    visited[i] = true;
    for(auto nbr:graph[i]){
        if(visited[nbr]==false){
            dfs(graph, nbr, visited, stack);
        }
    }
    stack.push_back(i);
}

void dfs2(vector<int> graph[], int i, bool *visited){
    visited[i] = true;
    cout<<i<<" ";
    for(auto nbr:graph[i]){
        if(visited[nbr]==false){
            dfs2(graph, nbr, visited);
        }
    }
}

void solve(vector<int> graph[], vector<int> reverse_graph[], int n){
    bool visited[n];
    memset(visited, 0, n);
    vector<int> stack;
    // step 1- need to store the vertices according to dfs finish time
    for(int i = 0; i<n; i++){
         if(!visited[i]){
            dfs(graph, i, visited, stack);
        }
    }
    // step 2- reverse the graph

    // step 3- do dfs according to ordering given in the stack
    char component_name = 'A';
    memset(visited, 0, n);
    for(int i = stack.size()-1; i>=0; i--){
        int node = stack[i];  
        if(!visited[node]){
            cout<<"component "<<component_name<<"--> ";
            dfs2(reverse_graph, node, visited);
            component_name++;
            cout<<endl;
        }
        
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> graph[n];
    vector<int> reverse_graph[n];
    while(m--){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        reverse_graph[y].push_back(x);
    }
    solve(graph, reverse_graph, n);
    return 0;
}