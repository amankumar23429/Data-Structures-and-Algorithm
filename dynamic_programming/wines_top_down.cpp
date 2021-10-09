#include<iostream>
#include<climits>
using namespace std;

int maximize_profit(int *wines, int i, int j, int y, int dp[][100]){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    int left_profit = wines[i]*y + maximize_profit(wines, i+1, j, y+1, dp);
    int right_profit = wines[j]*y + maximize_profit(wines, i, j-1, y+1, dp);
    int profit = max(left_profit, right_profit);
    dp[i][j] = profit;
    return profit;
}

int main(){
    int wines[] = {2, 3, 5, 1, 4};
    int n = sizeof(wines)/sizeof(int);
    int dp[100][100] = {0};
    cout<<maximize_profit(wines, 0,n-1, 1, dp);
    return 0;
}