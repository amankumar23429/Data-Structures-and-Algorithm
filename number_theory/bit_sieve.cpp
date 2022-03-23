#include <bits/stdc++.h>
using namespace std;

const int n = 10000000;
bitset<10000005> b;

void sieve(){
    b.set();
    vector<int> primes;
    b[0] = b[1] = 0;
    for(long long int i = 2; i<=n; i++){
        if(b[i]){
            primes.push_back(i);
            for(long long int j = i*i; j<=n; j=j+i){
                b[j] = 0; 
            }
        }
    }

    for(int i = 0; i<25; i++){
        cout<<primes[i]<<" ";
    }
    return;
}

int main (){
    sieve();
    return 0;
}