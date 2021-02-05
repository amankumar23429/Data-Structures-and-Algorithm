#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    arr[n] = -1;
    int max_num = -1;
    int result = 0;
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i = 0; i<n; i++){
        if (arr[i]>arr[i+1] && arr[i]>max_num){
            result++;
        }
        max_num = max(arr[i],max_num);
    }
    cout<<result;

    

    return 0;
}