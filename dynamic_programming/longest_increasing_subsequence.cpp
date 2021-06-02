#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int lis_bottom_up(int *arr, int n){
    int dp[n];
    int ans = 1;
    for(int i = 0; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;  
}

int lis_optimized(int *arr, int n){
    int dp[n+1];
    dp[0] = INT_MIN;
    for(int i = 1; i<=n; i++){
        dp[i] = INT_MAX;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dp[j]>arr[i] and arr[i]<dp[j+1]){
                dp[j+1] = arr[i];
            }
        }
    }
    int lis = 1;
    for(int j = 1; j<n; j++){
        if(dp[j]!=INT_MAX){
            lis = j;
        }
    }
    return lis;
}

int main(){
    int arr[] = {1, 5, 2, 3, 4, 9, 6, 10};
    int n = sizeof(arr)/sizeof(int);
    cout<<lis_bottom_up(arr, n)<<endl;
    cout<<lis_optimized(arr, n);
    return 0;
}