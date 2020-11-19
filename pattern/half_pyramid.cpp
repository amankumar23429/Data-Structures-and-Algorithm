#include<iostream>
using namespace std;
int main(){
    int n = 0;
    cout<<"enter a number";
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (j <= n-i){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}