#include<iostream>
using namespace std;

int linear_search(int *a, int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(a[i] == key){
        return i;
    }
    else{
        return linear_search(a, n, i+1, key);
    }
}

int last_occur(int *a, int i, int key){
    if(i==-1){
        return -1;
    }
    if(a[i] == key){
        return i;
    }
    else{
        return last_occur(a, i-1, key);
    }
}

void all_occur(int *a, int n, int i, int key){
    if(i==n){
        return;
    }

    if(a[i] == key){
        cout<<i<<" ";
    }
    all_occur(a, n, i+1, key);
}

int main(){
    int arr[] = {1,2,3,5,46,7,56,4,64,7,74,5,7,4,6,7,88,5,9,524,7,4,5};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    //cout<<linear_search(arr, n, 0, key);
    all_occur(arr, n, 0 ,key);
    return 0;
}