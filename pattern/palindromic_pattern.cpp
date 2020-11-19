#include<iostream>
using namespace std;

int main(){
    int n = 0;
    cin>>n;

    for (int i=1; i<=n; i++){
        for(int k=1; k<=n-i; k++){
            cout<<"  ";
        }
        for (int j=i; j>1; j--){
            cout<<j<<" ";
        }
        for (int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}