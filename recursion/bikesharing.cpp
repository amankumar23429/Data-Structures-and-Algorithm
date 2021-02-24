#include<iostream>
using namespace std;

int pairingWays(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    int ans = pairingWays(n-1) + (n-1)*pairingWays(n-2);
    
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<pairingWays(n);
    return 0;
}