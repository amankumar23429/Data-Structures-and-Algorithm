#include<iostream>
#include<list>
#include<unordered_map>
#include<climits>
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
        unordered_map<T, int> dist;
        queue<T> q;

        for(auto p:l){
            T node = p.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0; 
        q.push(src);
        
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto p:l[node]){
                if(dist[p]==INT_MAX){
                    q.push(p);
                    dist[p] = dist[node]+1;
                }
            }
        }

        for(auto p:dist){
            cout<<"dist from node "<<src<<" to node "<<p.first<<" is "<<p.second<<endl;
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