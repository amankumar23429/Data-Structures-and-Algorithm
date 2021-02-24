#include<iostream>
using namespace std;

int binary_search(int *a, int s, int e, int key){
    int mid = (s+e)/2;
    if(s>e){
        return -1;
    }
    if(key==a[mid]){
        return mid;
    }else if(key<a[mid]){
        return binary_search(a, s, mid-1, key);
    }else{
        return binary_search(a, mid+1, e , key);
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    cout<<binary_search(arr,0,n-1, key);
    return 0;
}