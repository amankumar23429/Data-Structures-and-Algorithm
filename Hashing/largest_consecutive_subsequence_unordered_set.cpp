#include<iostream>
#include<unordered_set>
using namespace std;

int findLargestSequence(int arr[], int n){
    unordered_set<int> s;
    int max_len = 0;
    for(int i = 0; i<n; i++){
        s.insert(arr[i]);
    }
    
    for(int i = 0; i<n; i++){
        if(s.find(arr[i]-1)==s.end()){
            int count = 1;
            int no = arr[i];
            while(s.find(no+1)!=s.end()){
                count++;
                no++;
            }
            max_len = max(max_len, count);
        }
    }
    return max_len;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    //int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
   cout<<findLargestSequence(arr, n);
    
    return 0;
}