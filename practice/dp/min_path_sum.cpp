#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> res(m);

    for(int j = 0; j < m; j++){
        res[j] = vector<int>(n);
    }

    for(int i = m-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            if(i==m-1 and j==n-1){
                res[i][j] = grid[m-1][n-1];
            }
            else if(i==m-1){
                res[i][j] = grid[i][j]+res[i][j+1];
            }
            else if(j==n-1){
                res[i][j] = grid[i][j]+res[i+1][j];
            }
            else{
                res[i][j] = grid[i][j] + min(res[i][j+1], res[i+1][j]);
            }
        }
    }
    for(auto p:res){
        for(auto q:p){
            cout<<q<<" ";
        }
        cout<<endl;
    }
    return res[0][0];
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
    
    cout<<minPathSum(grid);
    return 0;
}