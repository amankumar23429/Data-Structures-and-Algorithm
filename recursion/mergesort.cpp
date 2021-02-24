#include<iostream>
using namespace std;

void merge(int *a, int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100] = {0};

    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }

    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }

    for (int x = s; x<=e; x++){
        a[x] = temp[x];
    }
}

void merge_sort(int *a, int s, int e){
    if(s>=e){
        return; 
    }

    int mid = (s+e)/2;
    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);

    merge(a, s, e);
}

int main(){
    int arr[] = {5,6,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    merge_sort(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}