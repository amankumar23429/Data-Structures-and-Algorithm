#include<iostream>
#include<climits>
using namespace std;

int maximize_profit_top(int *prices, int n, int *dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(n>=i+1){
            int profit = prices[i] + maximize_profit_top(prices, n-(i+1), dp);
            ans = max(ans, profit);
        }
    }
    dp[n] = ans; 
    return ans;
}

int max_profit_bottom(int *prices, int n){
    int dp[n+1] = {0};
    int ans = INT_MIN;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<i; j++){
            int cut = j+1;
            int current_ans = prices[j] + dp[i-cut]; 
            ans = max(ans, current_ans);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main(){
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices)/sizeof(int);
    int dp[n+1] = {0};
    cout<<maximize_profit_top(prices, n, dp)<<endl;
    cout<<max_profit_bottom(prices, n);
    return 0;
}