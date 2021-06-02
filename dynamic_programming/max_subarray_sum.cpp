#include<iostream>
using namespace std;

int max_sum(int *arr, int n){
    int dp[n] = {0};
    dp[0] = arr[0]>0?arr[0]:0;
    int max_so_far = dp[0];
    for(int i = 1; i<n; i++){
        dp[i] = arr[i]+dp[i-1];
        if(dp[i]<0){
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;
}

// kadane algorithm
// one special case we have to handle if all elements are negative we have to return max element from that
int max_sum_space_opti(int *arr, int n){
    int max_so_far = 0;
    int cs = 0;
    for(int i = 0; i<n; i++){
        if(cs<0){
            cs = 0;
        }
        cs += arr[i];
        max_so_far = max(max_so_far, cs);
    }
    return max_so_far;
}

int main(){
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr)/sizeof(int);
    cout<<max_sum_space_opti(arr, n)<<endl;
    cout<<max_sum(arr,n);
    return 0;
}