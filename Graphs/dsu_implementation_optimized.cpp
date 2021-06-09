#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<pair<int, int>> l;
    
    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int x, int y){
        l.push_back(make_pair(x,y));
    }

    // path by compression
    int findSet(int i, int parent[]){
        if(parent[i]==-1){
            return i;
        }
        return parent[i] = findSet(parent[i], parent);
    }

    // rank by union
    void union_set(int x, int y, int parent[], int rank[]){
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    bool contains_cycle(){
        int *parent = new int[V];
        int *rank = new int[V];
        for(int i = 0; i<V; i++){
            parent[i] = -1;
            rank[i] = 1;
        }

        for(auto edge:l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1!=s2){
                union_set(s1, s2, parent, rank);
            }
            else{
                delete [] parent;
                return true;
            }
        }
        delete [] parent;
        return false;
    }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    cout<<g.contains_cycle();
    return 0;
}