#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool directed=true){
        l[x].push_back(y);
        if(!directed){
            l[y].push_back(x);
        }
    }

    bool cycle_helper(int node, bool *visited, int parent){
        visited[node] = true;

        for(auto nbr:l[node]){
            if(visited[nbr]==true and nbr!=parent){
                return true;
            }
            else if(!visited[nbr]){
                bool is_cycle = cycle_helper(nbr, visited, node);
                if(is_cycle){
                    return true;
                }
            }
        }
        return false; 
    }

    bool containsCycle(){
        bool *visited = new bool[V];

        for(int i = 0; i<V; i++){
            visited[i] = false;
        }
        return cycle_helper(0, visited, -1);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 4, false);
    g.addEdge(4, 0, false);
    if(g.containsCycle()){
        cout<<"Cycle is present";
    }else{
        cout<<"Cycle is not present";
    }
    return 0;
}