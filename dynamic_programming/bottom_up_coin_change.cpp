#include<iostream>
#include<climits>
using namespace std;

int min_coins(int *coins, int n, int money){
    int dp[money+1] = {0};
    for(int i = 1; i<=money; i++){
        int j = 0;
        int min_coins  = INT_MAX;
        while(j<n and coins[j]<=i){
            min_coins = min(min_coins, dp[i-coins[j]]);
            j++;
        }
        if(min_coins==INT_MAX){
            return -1;
        }
        else{
            dp[i] = min_coins+1;
        }
        
    }
    return dp[money];
}

int main(){
    int money;
    cin>>money;
    int coins[] = {1,7,10};
    int n = sizeof(coins)/sizeof(int);
    cout<<min_coins(coins, n, money)<<endl;
    return 0;
}