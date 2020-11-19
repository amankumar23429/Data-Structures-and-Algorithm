#include<iostream>
using namespace std;

int main(){
    int n = 0;
    cin>>n;

    for (int i=1; i<=n; i++){
        for(int k=1; k<=n-i; k++){
            cout<<" ";
        }
        for (int j = 1; j <= n; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}