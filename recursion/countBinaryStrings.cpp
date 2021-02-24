#include<iostream>
using namespace std;

int binaryWays(int n){
    if(n<=0){
        return 1;
    }
    
    int ans = binaryWays(n-1) + binaryWays(n-2);
    
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<binaryWays(n);
    return 0;
}