#include<iostream>
using namespace std;

void dnf_sort(int arr[], int n){
    int low = -1;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            low++;
            swap(arr[low], arr[mid++]);
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            swap(arr[mid], arr[high--]);
        }
    }
}

int main(){
    int arr[] = {2,1,1,1,1,0,1,1,1,0,0,2,0};
    int n = sizeof(arr)/sizeof(int);

    dnf_sort(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}