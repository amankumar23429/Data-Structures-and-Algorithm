#include<iostream>
using namespace std;

// method 1

int countBits(int n){
    int count = 0;
    while(n>0){
        count += (n&1);
        n = n>>1;
    }
    return count;
}

// method 2

int fastCountBits(int n){
    int ans = 0;
    while(n>0){
        n = n & (n-1);
        ans++;
    }
    return ans;
}


int main(){
    
    int n;
    cin>>n;
    cout<<countBits(n)<<endl;
    cout<<fastCountBits(n)<<endl;

    // builtin method

    cout<<__builtin_popcount(n);

    return 0;
}