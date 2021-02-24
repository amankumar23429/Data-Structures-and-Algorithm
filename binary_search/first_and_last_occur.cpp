#include<iostream>
using namespace std;

int first_occurence(int a[], int n, int key){
    int s = 0;
    int e = n;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;

        if(a[mid]==key){
            ans = mid;
            e = mid-1;
        }
        else if(a[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

int last_occurence(int a[], int n, int key){
    int s = 0;
    int e = n;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;

        if(a[mid]==key){
            ans = mid;
            s = mid+1;
        }
        else if(a[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

int main(){

    int n,key = 0;
    int a[100];

    cin >> n;

    for (int j = 0; j<n; j++){
        cin>>a[j];
    }
    
    cin >> key;

    cout << first_occurence(a, n, key) << endl;
    cout << last_occurence(a, n, key) << endl;
    

    return 0;

}