#include <bits/stdc++.h>
using namespace std;

const int n = 10000000;
bitset<10000005> b;
vector<long long int> primes;

void sieve(){
    b.set();
    
    b[0] = b[1] = 0;
    for(long long int i = 2; i<=n; i++){
        if(b[i]){
            primes.push_back(i);
            for(long long int j = i*i; j<=n; j=j+i){
                b[j] = 0; 
            }
        }
    }
    return;
}

bool isPrime(long long int num){
    if(num<=n){
        if(b[num]){
            return true;
        }
        return false;
    }

    for(long long int i = 0; primes[i]*primes[i]<=num; i++){
        if(num%primes[i]==0){
            return false;
        }
    }
    return true;
}

int main (){
    sieve();
    long long int n1;
    cin>>n1;
    cout<<isPrime(n1);
    return 0;
}