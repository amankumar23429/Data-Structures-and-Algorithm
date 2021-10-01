#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void bubble_sort(int a[], int j, int n){
    if(n==1){
        return;
    }
    if(j==n-1){
        return bubble_sort(a, 0, n-1);
    }
    if(a[j]>a[j+1]){
        swap(a[j], a[j+1]);
    }
    return bubble_sort(a, j+1, n);
}

int main (){
    //cout<<fast_expo(2,4);
    int arr[] = {5,4,5,3,2,1};
    bubble_sort(arr,0, 6);
    for(auto p:arr){
        cout<<p<<" ";
    }
    return 0;
}