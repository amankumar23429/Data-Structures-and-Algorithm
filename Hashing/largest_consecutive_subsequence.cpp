#include<iostream>
#include<unordered_map>
using namespace std;

int findLargestSequence(int arr[], int n){
    unordered_map<int, int> m;
    int count;
    
    for(int i = 0; i<n; i++){
        int no = arr[i];
        if(m.count(no-1)==1 and m.count(no+1)==1){
            int one_small_len = m[no-1];
            int one_large_len = m[no+1];
            count = one_small_len + one_large_len + 1;
            m[no-one_small_len] = count;
            m[no+one_large_len] = count;
        }
        else if(m.count(no-1)){
            count = m[no-1];
            count++;
            m[no-count+1] = count;
            m[no] = count;
        }
        else if(m.count(no+1)){
            count = m[no+1];
            count++;
            m[no+count-1] = count;
            m[no] = count;
        }
        else{
            m[no] = 1;
        }
    }
    int max_len = 0;
    for(auto p:m){
        max_len = max(max_len, p.second);
    }
    return max_len;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
   cout<<findLargestSequence(arr, n);
    
    return 0;
}