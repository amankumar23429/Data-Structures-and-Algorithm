#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> l;

    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
    }

    void topological_sort(){
       map<T, int> indegree;
        
        for(auto p:l){
            T node = p.first;
            indegree[node] = 0;
        }

        for(auto p:l){
            T node = p.first;
            for(auto nbr:p.second){
                indegree[nbr]++;
            }
        }

        queue<T> q;
        
        for(auto p:indegree){
            if(p.second==0){
                q.push(p.first);
            }
        }

        while(!q.empty()){
            T node = q.front();
            q.pop();

            cout<<node<<" ";
            for(auto nbr:l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }

};

int main(){
    Graph<int> g;
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(2,5);
    g.addEdge(1,4);
    g.addEdge(4,5);

    g.topological_sort();
    return 0;
}