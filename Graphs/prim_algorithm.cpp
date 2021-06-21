#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    vector<pair<int, int>> *l;
    int V;
    public:
    Graph(int n){
        V = n;
        l = new vector<pair<int, int>> [n];
    }

    void addEdge(int x, int y, int wt){
        l[x].push_back({y,wt});
        l[y].push_back({x,wt});
    }

    int prim_mst(){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
        bool *visited = new bool[V]{0};
        int ans = 0;
        q.push({0, 0});
        
        while(!q.empty()){
            auto best_pr = q.top();
            q.pop();
            int weight = best_pr.first;
            int nbr_node = best_pr.second; 

            if(visited[nbr_node]){
                continue;
            }

            visited[nbr_node] = true;
            ans += weight;

            for(auto nb:l[nbr_node]){
                if(!visited[nb.first]){
                    q.push({nb.second, nb.first});
                }
            }
        }
        return ans;
    }
};

int main(){ 
    int n, m;
    cin>>n>>m;
    Graph g(n);
    int x, y, w;
    for(int i = 0; i<m; i++){
        cin>>x>>y>>w;
        g.addEdge(x-1, y-1, w);
    }
    cout<<g.prim_mst();
    return 0;
}
