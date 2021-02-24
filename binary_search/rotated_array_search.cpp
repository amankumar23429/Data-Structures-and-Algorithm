#include<iostream>
using namespace std;

int find_key(int a[], int n, int key){
    int s = 0;
    int e = n-1;

    while(s<=e){
        int mid = (s+e)/2;

        if(a[mid]==key){
            return mid;
        }
        else if(a[s] <= a[mid]){
            if(key<=a[mid] && key>=a[s]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        else{
            if(key >= a[mid] && key<=a[e]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    }
    return -1;
}

int main(){

    int n,key = 0;
    

    cin >> n;
    int a[n];

    for (int j = 0; j<n; j++){
        cin>>a[j];
    }
    
    cin >> key;

    cout << find_key(a,n,key);
    
    return 0;

}