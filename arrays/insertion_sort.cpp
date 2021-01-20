#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    
    for(int i = 1; i < n; i++){
        int e = arr[i];
        int j = i-1;

        while(arr[j] > e and j >= 0){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = e;
    }
}

int main(){
    int a[100] = {0};
    int n = 0;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    insertion_sort(a,n);

    for(int i = 0; i<n; i++){
        cout<<a[i]<<endl;
    }
    
    return 0;
}