#include<iostream>
#include<unordered_map>
using namespace std;


int max_subarray_sum_k(int arr[], int n, int k){
    int max_length = 0;
    unordered_map<int, int> m;
    int cs = 0;
    for(int i = 0; i<n; i++){
        cs += arr[i];
        if(cs==k){
            max_length = max(max_length, i+1);
        }
        if(m.count(cs-k)){
            max_length = max(max_length, i-m[cs-k]);
        }else{
            m[cs] = i;
        }
    }
    return max_length;
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<max_subarray_sum_k(arr, n, k)<<endl;
    
    return 0;
}