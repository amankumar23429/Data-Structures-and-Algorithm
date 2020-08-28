#include<iostream>
using namespace std;

int main(){
    int n,i,key = 0;
    int a[100];
    cout<< "enter the total elements in an array";
    cin>> n;

    cout<<"enter the elements of an array";
    for (int j = 0; j<n; j++){
        cin>>a[j];
    }
    
    cout<<"enter number which you want to found in array";
    cin>> key;
    for (i=0; i<n; i++){
        if(a[i] == key){
            cout<<"number " << key << " is found at index at "<< i;
            break;
        } 
    }

    if (i == n){
            cout<<"not found in array";
        }
    
    return 0;
}