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

int max_profit_bottomUp(int* wines, int n){
    int dp[n][n] = {0};
    int i = 0;
    int j = 0;
    while(i<n and j<n){
        dp[i][j] = wines[i] * n;
        i++;
        j++;
    }

    for(int k = 1; k<n; k++){
        i=0;
        j=k;
        while(i<n and j<n){
            int m = INT_MIN;
            int op1 = wines[i]*(j-i+1) + dp[j][j];
            int op2 = wines[i+1]*(j-i+1) + dp[j-1][j-1];
            m = max(op1, op2);
            //cout<<dp[j][j]<< " "<<dp[j-1][j-1]<<endl;
            cout<<op1<< " "<<op2<<endl;
            dp[i][j] = m;
            i++;
            j++;
        }
    }
    return dp[0][1];
}

int main(){
    int wines[] = {2, 3, 5};
    int n = sizeof(wines)/sizeof(int);
    int dp[100][100] = {0};
    cout<<max_profit_bottomUp(wines, n);
    return 0;
}