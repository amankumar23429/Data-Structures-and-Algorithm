#include<iostream>
using namespace std;

bool isSorted(int *a, int n){
    if(n==1 or n==0){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    bool isSmallerSorted = isSorted(a+1, n-1);
    // if(isSmallerSorted==true){
    //     return true;
    // }
    // return false;
    return isSmallerSorted;
}

int main(){
    int arr[] = {1,2,3,14,5};
    int n = sizeof(arr)/sizeof(int);

    cout<<isSorted(arr,n);
    return 0;
}