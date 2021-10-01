#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int isSubsetSum(vector<int> v, int tar){
    int m = v.size()+1;
    int n = tar+1;

    vector<vector<int>> dp(m);
    for(int j = 0; j < m; j++){
        dp[j] = vector<int>(n);
    }

    for(ll i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(j==0){
                dp[i][j] = 1;
            }
            else if(i==0){
                dp[i][j] = 0;
            }
            else{
                int val = v[i-1];
                if(dp[i-1][j]==1){
                    dp[i][j] = 1;
                }
                else if(j>=val){
                    if(dp[i-1][j-val]==1){
                        dp[i][j] = 1;
                    }
                }
            }
        }
    }
    // for(ll i = 0; i<m; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[v.size()][tar];
}

int main (){
    ll n;
    cin>>n;
    vector<int> v;
    for(ll i = 0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    int target;
    cin>>target;
    if(isSubsetSum(v,target)==1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}