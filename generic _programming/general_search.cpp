#include<iostream>
#include<list>
using namespace std;

template<typename T>
int search(T arr[], int n, T key){
    for(int i = 0; i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return n;
}


int main(){
    int arr[] = {1,2,3,4,5};
    //cout<<search(arr, 5, 3);

    float farr[] = {3.6, 2.5, 1.5};
    float key = 2.5;
    cout<<search(farr, 3, key);

    return 0;
}