#include<iostream>
#include<climits>
using namespace std;

int min_steps_top_down(int n, int* dp){
    if(n==1){
        return 0;
    }
    int min_1,min_2,min_3;
    min_1 = min_2 = min_3 = INT_MAX;
    if(dp[n]!=0){
        return dp[n];
    }
    if(n%2==0){
        min_1 = min_steps_top_down(n/2, dp);
    }
    if(n%3==0){
        min_2 = min_steps_top_down(n/3, dp);
    }
    min_3 = min_steps_top_down(n-1, dp);
    int ans = min(min(min_1, min_2), min_3)+1;
    dp[n] = ans;
    return ans;
}

int min_steps_bottom_up(int n){
    int dp[n+1] = {0};
    for(int i = 2; i<=n; i++){
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(i%2==0){
            op1 = dp[i/2];
        }
        if(i%3==0){
            op2 = dp[i/3];
        }
        op3 = dp[i-1];
        dp[i] = min(min(op1, op2), op3)+1;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int dp[n+1] = {0};
    cout<<min_steps_top_down(n, dp)<<endl;
    cout<<min_steps_bottom_up(n)<<endl;
    return 0;
}