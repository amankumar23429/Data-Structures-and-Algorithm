#include<iostream>
using namespace std;

int *fun(){
    int *a = new int[5];
    a[0] = 34;
    a[1] = 45;
    cout<<a<<endl;
    cout<<a[0]<<endl;
    return a;
}

int main(){
    int *arr = fun();
    cout<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<arr[1];

    delete [] arr;
    
    return 0;
}