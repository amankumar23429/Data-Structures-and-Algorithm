#include<bits/stdc++.h>
using namespace std;

int MCM(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    int ans = INT_MAX;
    for(int k = i; k<j; k++){
        int count = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, count);
    }
    return ans;
}

int main(){
    int arr[] = {40, 20, 30, 10 , 30};
    cout<<MCM(arr, 1, 4);
    return 0;
}