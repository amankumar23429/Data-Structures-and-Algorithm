#include<iostream>
#include<unordered_map>
using namespace std;


int max_length_subarray(int arr[], int n){
    int max_length = 0;
    unordered_map<int, int> m;
    int cs = 0;
    for(int i = 0; i<n; i++){
        cs += arr[i];
        if(m.count(cs) or cs==0){
            int curr_len = 0;
            if(cs==0){
                curr_len = i+1;
            }else{
                curr_len = i-m[cs];
            }
            max_length = max(max_length, curr_len);
        }else{
            m[cs] = i;
        }
        
    }
    return max_length;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<max_length_subarray(arr, n)<<endl;
    
    return 0;
}