#include<iostream>
using namespace std;
int main(){
    int n = 0;
    cout<<"enter a number";
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cout<<"*";
        }
        for (int a=1; a<=(2*n-2*i); a++){
            cout<<" ";
        }
        for (int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for (int i=n; i>0; i--){
        for (int j=1; j<=i; j++){
            cout<<"*";
        }
        for (int a=1; a<=(2*n-2*i); a++){
            cout<<" ";
        }
        for (int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}