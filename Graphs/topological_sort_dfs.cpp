#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    int V;
    map<T, list<T>> l;
    public:

    void addEdge(T x, T y){
        l[x].push_back(y);
    }

    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering){
        visited[src] = true;
        for(auto nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
    }

    void dfs_connected(){
        map<T, bool> visited;
        list<T> ordering;
        for(auto p:l){
            T node = p.first;
            visited[node] = false;
        }

        for(auto p:l){
            T node = p.first;    
            if(!visited[node]){
                dfs_helper(node, visited, ordering);
            }   
        } 

        for(auto n:ordering){
            cout<<n<<endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "Pytorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("Pytorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("Dataset", "FaceRecogn");
    g.dfs_connected();
    return 0;
}