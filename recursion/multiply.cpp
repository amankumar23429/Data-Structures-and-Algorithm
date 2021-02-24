#include<iostream>
using namespace std;

int mul(int a, int n){
    if(n==1){
        return a;
    }
    return a+mul(a,n-1);
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<mul(max(a,n),min(a,n));
    return 0;
}