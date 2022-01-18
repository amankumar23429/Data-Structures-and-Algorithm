#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> l;
public:
    void addEdge(T x, T y){
        l[x].push_back(y);
    }

    int bfs(T src, T dest){
        unordered_map<T, int> dist;
        queue<T> q;
        unordered_map<T,T> parent;

        for(auto p:l){
            T node = p.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto p:l[node]){
                if(dist[p]==INT_MAX){
                    q.push(p);
                    dist[p] = dist[node]+1;
                    parent[p] = node;
                }
            }
        }
        T temp = dest;
        while(src!=temp){
            cout<<temp<<" <--";
            temp = parent[temp];
        }
        cout<<src<<endl;
        return dist[dest];
    }
};

int main(){
    Graph<int> g;
    int board[50];
    memset(board, 0, sizeof(board));
    board[2] = 13;
    board[5] = 2;
    board[17] = -13;
    board[18] = 11;
    board[24] = -8;
    board[9] = 18;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    for(int i = 0; i<=36; i++){
        for(int dice = 1; dice<=6; dice++){
            int j = i+dice;
            j += board[j];

            if(j<=36){
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36,36);
    cout<<g.bfs(0,36)<<endl;
    return 0;
}