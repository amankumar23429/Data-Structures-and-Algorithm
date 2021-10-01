#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[1000];
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    for(int x = s; x<k; x++){
        arr[x] = temp[x];
    }
    return;
}

void merge_sort(int a[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    merge_sort(a,s, mid);
    merge_sort(a, mid+1, e);
    merge(a,s,e);
    return;
}

int main (){
    //cout<<fast_expo(2,4);
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    merge_sort(arr,0, n-1);
    for(auto p:arr){
        cout<<p<<" ";
    }
    return 0;
}