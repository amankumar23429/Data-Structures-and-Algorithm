#include<iostream>
using namespace std;

int fib(int n, int *dp){
    // base case
    if(n==0 or n==1){
        return n;
    }
    // look up
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = fib(n-1, dp)+ fib(n-2, dp);
    dp[n] = ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int dp[n+1] = {0};
    cout<<fib(n,dp);
    return 0;
}