#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool isTree(){
        bool *visited = new bool[V];
        int *parent = new int[V];
        queue<int> q;
        for(int i = 0; i<V; i++){
            visited[i] = false;
            parent[i] = i;
        }

        int src = 0;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr:l[node]){
                if(visited[nbr]==true and parent[node]!=nbr){
                    return false;
                }
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = node;
                    visited[nbr] = true;
                }
            }
        }
        return true;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    if(g.isTree()){
        cout<<"Yes, it is a tree";
    }else{
        cout<<"No, it is not a tree";
    }  
    return 0;
}