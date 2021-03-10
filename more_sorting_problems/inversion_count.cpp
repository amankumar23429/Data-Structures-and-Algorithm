#include<iostream>
using namespace std;

int crossInversion(int *arr, int s, int e){
    int mid = (s+e)/2;
    
    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100];
    int cnt = 0;

    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            cnt += mid-i+1;
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }

    while(j<=e){
        temp[k++] = arr[j++];
    }

    for(int x = 0; x<k; x++){
        arr[x] = temp[x];
    }

    return cnt;
}

int inversion_count(int a[], int s, int e){
    if(s>=e){
        return 0;;
    }
    
    int mid = (s+e)/2;
    int x = inversion_count(a, s, mid);
    int y = inversion_count(a, mid+1, e);

    int z = crossInversion(a, s, e);

    return x+y+z;
}

int main(){
    
    int arr[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(arr)/sizeof(int);

    cout<<inversion_count(arr, 0, n-1);

    // for(int i = 0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    
    return 0;
}