#include<iostream>
using namespace std;

int partition(int *a, int s, int e){
    int pivot = a[e];
    int i = s-1;
    int j = s;
    for (; j<e; j++){
        if (a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[e]);
    return i+1;
}

void quick_sort(int *a, int s, int e){
    if(s>=e){
        return; 
    }

    int p = partition(a, s, e);

    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);
}

int main(){
    int arr[] = {5,6,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    quick_sort(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}