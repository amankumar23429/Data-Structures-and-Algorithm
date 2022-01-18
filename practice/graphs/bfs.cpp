#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> l;
public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
        unordered_map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto p:l[node]){
                if(!visited[p]){
                    q.push(p);
                    visited[p] = true;
                }
            }
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,0);
    g.bfs(0);
    return 0;
}