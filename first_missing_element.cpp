#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    //const int N = 1e6 +2;
    bool bool_arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i<n; i++){
        bool_arr[i] = 0;
    }

    for(int i = 0; i<n; i++){
        if(arr[i]>=0){
            bool_arr[arr[i]] = 1;
        }
    }
    int ans = -1;

    for(int i = 1; i<n; i++){
        if(bool_arr[i]==false){
            ans = i;
            break;
        }
    }

    cout<<ans;

    return 0;
}