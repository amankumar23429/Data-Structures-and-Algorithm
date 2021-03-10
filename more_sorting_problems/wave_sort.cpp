#include<iostream>
using namespace std;

void wave_sort(int arr[], int n){
    for(int i = 0; i<n; i+=2){
        // left check
        if(i!=0 && arr[i]<arr[i-1]){
            swap(arr[i], arr[i-1]);
        }

        //right check
        if(i!=n-1 && arr[i]<arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1, 3, 4, 2, 7, 8};
    int n = sizeof(arr)/sizeof(int);

    wave_sort(arr, n);
    

    return 0;
}