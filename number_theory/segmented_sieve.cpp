#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int n1 = 100000;
bitset<100005> b;
vector<ll> primes;

void sieve(){
    b.set();
    
    b[0] = b[1] = 0;
    for(long long int i = 2; i<=n1; i++){
        if(b[i]){
            primes.push_back(i);
            for(long long int j = i*i; j<=n1; j=j+i){
                b[j] = 0; 
            }
        }
    }
    return;
}

int main (){
    sieve();
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>m>>n;
        bool segment[n-m+1];
        for(ll i = 0; i<n-m+1; i++){
            segment[i] = 1;
        }

        for(auto x:primes){
            if(x*x>n){
                break;
            }
            ll start = (m/x)*x;
            if(x>=m and x<=n){
                start = x*2;
            }
            for(ll i = start; i<=n; i+=x){
                if(i-m>=0){
                    segment[i-m] = 0;
                }
            }
        }
        for(ll i = m; i<=n; i++){
            if(segment[i-m]==1 and i!=1){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}