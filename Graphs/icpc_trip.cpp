#include<iostream>
#include<list>
#include<unordered_map>
#include<climits>
#include<set>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T, pair<int, int>>>> l;
    public:

    void addEdge(T x, T y,  int trainP, int aeroP, bool bidir = true){
        l[x].push_back(make_pair(y,make_pair(trainP, aeroP)));
        if(bidir){
            l[y].push_back(make_pair(x, make_pair(trainP, aeroP)));
        }  
    }

    void printAdjList(){ 
        for(auto p:l){
            cout<<p.first<<" -> ";
            list<pair<T, pair<int, int>>> nbrs = p.second;
            for(auto nbr:nbrs){
                cout<<"("<<nbr.first<<" , "<<nbr.second.first<<", "<<nbr.second.second<<") ";
            }
            cout<<endl;
        }
    }

    void dijkstraSSSP(T src, unordered_map<T, int> &dist){
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
                if(nodeDist+ childPair.second.first < dist[childPair.first]){
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));

                    if(f!=s.end()){
                        s.erase(f);
                    }

                    dist[dest] = nodeDist + childPair.second.first;
                    s.insert(make_pair(dist[dest], dest));
                }
                
            } 
        }
        // for(auto dis:dist){
        //     cout<<dis.first<<" is located at "<<dis.second<<endl;
        // }
    }

    void calculate_fair(T src, T dest){
        unordered_map<T,int> dist_src;
        unordered_map<T,int> dist_dest;
        dijkstraSSSP(src, dist_src);
        dijkstraSSSP(dest, dist_dest);
        int min_fair = dist_src[dest];

        for(auto p:l){
            T node = p.first;
            for(auto nbr:l[node]){
                int current_fair = dist_src[node] + dist_dest[nbr.first] + nbr.second.second;
                min_fair = min(min_fair, current_fair);
                //cout<<current_fair<<" "<<min_fair<<endl;
            }
        }
        cout<<min_fair;
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Amritsar", "Delhi", 3, 8);
    g.addEdge("Amritsar", "Jaipur", 5, 4);
    g.addEdge("Jaipur", "Delhi", 2, 6);
    g.addEdge("Delhi", "Bhopal", 7, 14);
    g.addEdge("Jaipur", "Pune", 6, 5);
    g.addEdge("Pune", "Goa", 11, 6);
    g.addEdge("Pune", "Mumbai", 8, 7);
    g.addEdge("Mumbai", "Bhopal", 6, 3);
    g.addEdge("Goa", "Amritapuri", 13, 12);
    g.addEdge("Mumbai", "Amritapuri", 8, 7);
    g.addEdge("Bhopal", "Amritapuri", 12, 4);
    
    
    g.calculate_fair("Delhi", "Amritapuri");
    return 0;
}