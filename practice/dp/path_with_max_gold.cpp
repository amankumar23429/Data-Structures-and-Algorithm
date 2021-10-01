#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> res(m);

    for(int j = 0; j < m; j++){
        res[j] = vector<int>(n);
    }

    for(int i = n-1; i>=0; i--){
        for(int j = 0; j<m; j++){
            if(i==n-1){
                res[j][i] = grid[j][i];
            }
            else if(j==0){
                res[j][i] = grid[j][i] + max(res[j][i+1],res[j+1][i+1]);
            }
            else if(j==m-1){
                res[j][i] = grid[j][i] + max(res[j][i+1],res[j-1][i+1]);
            }
            else{
                res[j][i] = grid[j][i] + max(res[j][i+1],max(res[j-1][i+1], res[j+1][i+1]));
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<m; i++){
        ans = max(res[i][0], ans);
    }
    return ans;
}

int main (){
    ll n,m;
    cin>>m>>n;
    vector<vector<int>> grid(m);
    for(ll i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            int num;
            cin>>num;
            grid[i].push_back(num);
        }
    }

    // for(ll i = 0; i<m; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    // }
    
    cout<<getMaximumGold(grid);
    return 0;
}