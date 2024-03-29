#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    unordered_map<string, list<pair<string, int>>> l;
public:
    void addEdge(string x, string y, bool bidir, int wt){
        l[x].push_back({y,wt});
        if(bidir){
            l[y].push_back({x,wt});
        }
    }

    void print(){
        for(auto p:l){
            list<pair<string, int>> nbrs = p.second;
            cout<<p.first<<"-> ";
            for(auto nbr:nbrs){
                cout<<nbr.first<<" "<<nbr.second<<" , ";
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
    g.print();
    return 0;
}