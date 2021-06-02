#include<iostream>
#include<climits>
using namespace std;

int total_ways(int n , int k, int *dp){
    if(n==0){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = 0;
    for(int i = 1; i<=k; i++){
        if(n-i>=0){
            ans += total_ways(n-i, k, dp);
        }
    }
    dp[n] = ans;
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    int dp[n+1] = {0};
    cout<<total_ways(n, k, dp);
    return 0;
}