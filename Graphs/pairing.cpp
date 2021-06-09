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

    int pairing(){
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

            union_set(s1, s2, parent, rank);
        }
        int ans = 0;
        for(int i = 0; i<V; i++){
            ans += V-rank[findSet(i, parent)];
        }
        delete [] parent;
        delete [] rank;
        return ans/2;
    }
};

int main(){
    int vertices, edge;
    cin>>vertices>>edge;
    Graph g(vertices);
    int x, y;
    for(int i = 0; i<edge; i++){
        cin>>x>>y;
        g.addEdge(x,y);
    }
    cout<<g.pairing();
    return 0;
}