#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000][1000];
ll arr[1000];

ll sum(int s, int e){
    ll ans = 0;
    for(int i = s; i<=e; i++){
        ans += arr[i];
        ans %= 100;
    }
    return ans;
}

ll solve_mixtures(int i, int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for(int k = i; k<=j; k++){
        dp[i][j] = min(dp[i][j], solve_mixtures(i, k) + solve_mixtures(k+1, j) + sum(i, k)*sum(k+1, j));
    }
   return dp[i][j];
}

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }

        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=n; j++){
                dp[i][j] = -1;
            }
        }
        cout<<solve_mixtures(0, n-1)<<endl;
    }

    return 0;
}