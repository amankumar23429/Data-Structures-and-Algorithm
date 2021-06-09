#include<iostream>
#include<list>
#include<unordered_map>
#include<climits>
#include<set>
using namespace std;

template<typename T>
class Graph{
    int V;
    unordered_map<T, list<pair<T, int>>> l;
    public:

    void addEdge(T x, T y,  int wt, bool bidir = true){
        l[x].push_back(make_pair(y, wt));
        if(bidir){
            l[y].push_back(make_pair(x, wt));
        }  
    }

    void printAdjList(){ 
        for(auto p:l){
            cout<<p.first<<" -> ";
            list<pair<T, int>> nbrs = p.second;
            for(auto nbr:nbrs){
                cout<<nbr.first<<" "<<nbr.second<<", ";
            }
            cout<<endl;
        }
    }

    void dijkstraSSSP(T src){
        //unordered_map<T,bool> visited;
        unordered_map<T,int> dist;

        for(auto p:l){
            dist[p.first] = INT_MAX;
        }

        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));

        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;

            s.erase(s.begin());

            for(auto childPair:l[node]){
                if(nodeDist+ childPair.second < dist[childPair.first]){
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));

                    if(f!=s.end()){
                        s.erase(f);
                    }

                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
                
            } 
        }
        for(auto dis:dist){
            cout<<dis.first<<" is located at "<<dis.second<<endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Amritsar", "Delhi", 1);
    g.addEdge("Amritsar", "Jaipur", 4);
    g.addEdge("Jaipur", "Delhi", 2);
    g.addEdge("Jaipur", "Mumbai", 8);
    g.addEdge("Bhopal", "Agra", 2);
    g.addEdge("Mumbai", "Bhopal", 3);
    g.addEdge("Agra", "Delhi", 1);
    g.dijkstraSSSP("Amritsar");

    // Graph<int> g;
    // g.addEdge(1, 2, 1);
    // g.addEdge(1, 3, 4);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 2);
    // g.addEdge(1,4, 7);

    // g.dijkstraSSSP(1);
    //g.printAdjList();
    return 0;
}