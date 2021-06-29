#include<bits/stdc++.h>
using namespace std;

int dp[1000];
int no_of_bst_possible(int n){
    if(n==0 or n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans += no_of_bst_possible(i-1)*no_of_bst_possible(n-i);
    }
    return dp[n] = ans;
}

int main(){
    int n;
    cin>>n;
    memset(dp,-1, 1000);
    cout<<no_of_bst_possible(n);
}
