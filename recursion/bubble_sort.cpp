#include<iostream>
using namespace std;

void bubble_sort(int *a, int i, int j, int n){
    if(i==n-1){
        return;
    }
    if(j==(n-i-1)){
        i++;
        j = 0;
    }
    if(a[j]>a[j+1]){
        swap(a[j], a[j+1]);
    }
    bubble_sort(a, i, j+1 , n);
}

void bubble_sort_recursive(int a[], int j, int n){
    if(n==1){
        return;
    }
    if(j==n-1){
        return bubble_sort_recursive(a,0,n-1);
    }
    if(a[j]>a[j+1]){
        swap(a[j], a[j+1]);
    }
    bubble_sort_recursive(a, j+1 , n);
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    //bubble_sort(arr, 0, 0, n);
    bubble_sort_recursive(arr,0,n);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}