#include<iostream>
using namespace std;


int main(){
    int a[100] = {0};
    int n = 0;

    cin>>n;

    // takes array input
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            for(int k = i; k<=j; k++){
                cout<<a[k];
            }
            cout<<endl;
        }
    }
    
    return 0;
}