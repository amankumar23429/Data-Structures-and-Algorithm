#include<iostream>
#include<climits>
using namespace std;

int total_ways(int n , int k){
    int dp[n+1] = {0};
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=k; j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[n];
}

int optimized_total_ways(int n , int k){
    int dp[n+1] = {0};
    dp[0] = dp[1] = 1;
    for(int i = 2; i<=k; i++){
        dp[i] = dp[i-1]*2;
    }

    for(int i = k+1; i<=n; i++){
        dp[i] = dp[i-1]*2 - dp[i-k-1];
    }

    return dp[n];
}

int main(){
    int n, k;
    cin>>n>>k;
    int dp[n+1] = {0};
    cout<<total_ways(n, k)<<endl;
    cout<<optimized_total_ways(n, k);
    return 0;
}