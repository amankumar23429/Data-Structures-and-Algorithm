#include<iostream>
using namespace std;

int binary_search(int a[], int n, int key){
    int s = 0;
    int e = n-1;

    while(s<=e){
        int mid = (s+e)/2;

        if(a[mid]==key){
            return mid;

        }
        else if(a[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;

}

int main(){

    int n,key = 0;
    int a[100];
    cout << "enter the total elements in an array";
    cin >> n;

    cout << "enter the elements of an array";
    for (int j = 0; j<n; j++){
        cin>>a[j];
    }
    
    cout << "enter number which you want to found in array";
    cin >> key;

    //return binary function outpu.0t
    cout << binary_search(a, n, key) << endl;

    return 0;

}