#include<iostream>
#include<vector>
#define ll long long
using namespace std;

vector<int> prime_sieve(int *arr, int n){
    vector<int> allPrime;
    allPrime.clear();
    allPrime.push_back(2);
    for(ll int i = 3; i<=n; i+=2){
        arr[i] = 1;
    }

    for(ll int i = 3; i<=n; i+=2){
        if(arr[i]==1){
            allPrime.push_back(i);
            for(ll int j = i*i; j<=n; j+=i){
                arr[j] = 0;
            }
        }
    }
    arr[2] = 1;
    arr[0] = arr[1] = 0;
    return allPrime;
}

vector<int> prime_factors(int n, vector<int> &prime){
    vector<int> factors;
    factors.clear();
    int i = 0;
    int p = prime[i];

    while(p*p<=n){
        if(n%p==0){
            factors.push_back(p);
            while(n%p==0){
                n = n/p;
            } 
        }
        i++;
        p = prime[i];
    }

    if(n!=1){
        factors.push_back(n);
    }

    return factors;
}

int main(){
    
    int arr[100000] = {0};
    vector<int> primes = prime_sieve(arr, 10000);

    int t;
    cin>>t;
    while(t--){
        int no;
        cin>>no;
        vector<int> factors = prime_factors(no,primes);
        for(auto x:factors){
            cout<<x<<endl;
        }
    } 
    return 0;
}