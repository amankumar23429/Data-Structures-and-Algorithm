#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    int V;
    unordered_map<string, list<pair<string, int>>> l;
    public:

    void addEdge(string x, string y, bool bidir, int wt){
        l[x].push_back(make_pair(y, wt));
        if(bidir){
            l[y].push_back(make_pair(x, wt));
        }  
    }

    void printAdjList(){ 
        for(auto p:l){
            string city = p.first;
            cout<<city<<" -> ";
            list<pair<string, int>> nbrs = p.second;
            for(auto nbr:nbrs){
                cout<<nbr.first<<" "<<nbr.second<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.printAdjList();
    return 0;
}