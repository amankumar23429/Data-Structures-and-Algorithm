#include<iostream>
#include<climits>
using namespace std;

int min_coins_top_down(int *coins, int *dp, int n, int money){
    if(money == 0){
        return 0;
    }
    if(dp[money]!=0){
        return dp[money];
    }
    int min_coins = INT_MAX;
    for(int i = 0; i<n; i++){
        if(coins[i]<=money){
            min_coins = min(min_coins, min_coins_top_down(coins, dp, n, money-coins[i]));
        }      
    }
    dp[money] = min_coins+1;
    return dp[money];
}

int main(){
    int money;
    cin>>money;
    int coins[] = {1, 7, 10};
    int dp[money+1] = {0};
    int n = sizeof(coins)/sizeof(int);
    cout<<min_coins_top_down(coins, dp,n, money)<<endl;
    return 0;
}