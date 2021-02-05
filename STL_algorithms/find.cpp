#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1,2,3,4};
    int key,n;
    n = sizeof(arr)/sizeof(int);

    cin>>key;
    
    auto it = find(arr, arr+n, key);
    int index = it-arr;

    if(index == n){
        cout<<key<<" not found";
    }else{
        cout<<index;
    }
    
    return 0;
}