#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class dsu{
    vector<int> parent;
    public:
    dsu(int n){
        for(int i = 0; i<n; i++){
            parent.push_back(i);
        }
    }

    int get(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i] = get(parent[i]);
    }

    void unite(int x, int y){
        int s1 = get(x);
        int s2 = get(y);
        
        if(s1!=s2){
            parent[s1] = max(parent[s1], parent[s2]);
            parent[s2] = max(parent[s1], parent[s2]);
        }
    }
};

int main (){
    ll n,q;
    cin>>n>>q;
    int l[q], r[q], c[q];
    for(ll i = 0; i<q; i++){
        cin>>l[i]>>r[i]>>c[i];
    }
    int res[n+2] = {0};
    dsu G(n+2);
    for(int i = q-1; i>=0; i--){
        int index = G.get(l[i]);
        while(index<=r[i]){
            res[index] = c[i];
            G.unite(index, index+1);
            index = G.get(index);
        }
    }
    for(int i = 1; i<=n; i++){
        cout<<res[i]<<endl;
    }
    return 0;
}