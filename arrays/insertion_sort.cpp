#include<iostream>
using namespace std;

void insertion_sort(int a[], int n){
    for (int i = 0; i<n; i++){
        int current = a[i];
        int j = i-1;
        while(current<a[j] && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]= current;
    }
}

int main(){
    int n =0;
    cin>>n;
    int a[n];

    for (int i = 0; i<n; i++){
        cin>>a[i];
    }

    insertion_sort(a, n);
     
    for (int j = 0; j<n; j++){
        cout<<a[j]<<" ";
    }
    return 0;
}