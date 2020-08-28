#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n, largest, smallest;
    int a[100];
    cout<< "enter the total elements in an array";
    cin>> n;

    cout<<"enter the elements of an array";
    for (int j = 0; j<n; j++){
        cin>>a[j];
    }
    largest = INT_MIN;
    smallest = INT_MAX;

    for (int i = 0; i<n; i++){
        if(a[i]>largest){
            largest = a[i];
        }
        if(a[i]<smallest){
            smallest = a[i];
        }
    }
    cout<<"largest number in array is "<<largest;
    cout<<"smallest number in array is "<<smallest;
    return 0;
}