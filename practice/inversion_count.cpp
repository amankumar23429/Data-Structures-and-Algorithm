#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int cross_inversion(int arr[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[1000];
    int count = 0;
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            count += mid-i+1;
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
    return count;
}

int inversion_count(int a[], int s, int e){
    if(s>=e){
        return 0;
    }
    int mid = (s+e)/2;
    int x = inversion_count(a,s, mid);
    int y = inversion_count(a, mid+1, e);
    int z = cross_inversion(a,s,e);
    return x+y+z;
}

int main (){
    //cout<<fast_expo(2,4);
    int arr[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(arr)/sizeof(int);
    cout<<inversion_count(arr,0, n-1)<<endl;
    return 0;
}