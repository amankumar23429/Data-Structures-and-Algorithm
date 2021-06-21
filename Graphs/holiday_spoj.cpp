#include<iostream>
#include<list>
#define ll long long
using namespace std;

class Graph{
    int V;
    list<pair<int, int>> *l;
    public:

    Graph(int V){
        this->V = V;
        l = new list<pair<int, int>>[V];
    }
    void addEdge(int x, int y, int cost){
        l[x].push_back({y,cost});
        l[y].push_back({x, cost});
    }

    int dfs_helper(int node, bool *visited, int *count, ll &ans){
        visited[node] = true;
        count[node] = 1;
        for(auto nbr_pair:l[node]){
            int nbr = nbr_pair.first;
            int cost= nbr_pair.second;
            if(!visited[nbr]){
                count[node] += dfs_helper(nbr, visited, count, ans);
                int nx = count[nbr];
                int ny = V-count[nbr];
                ans += 2 * min(nx, ny) * cost;
            }    
        }
        return count[node];
    }

    ll dfs(){
        bool *visited = new bool[V];
        int *count = new int[V];

        for(int i = 0; i<V; i++){
            visited[i] = false;
            count[i] = 0;
        }
        ll ans = 0;
        dfs_helper(0, visited, count, ans);
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    int count = 1;
    while(t>0){
        int n;
        cin>>n;
        Graph g(n);
        int x, y, w;
        for(int i = 0; i<n-1; i++){
            cin>>x>>y>>w;
            g.addEdge(x-1, y-1, w);
        }
        cout<<"Case #"<<count<<": "<<g.dfs()<<endl;
        count++;
        t--;
    }
    return 0;
}