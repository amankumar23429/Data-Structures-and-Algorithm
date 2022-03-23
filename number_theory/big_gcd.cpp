#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll reduce(string s, ll m){
    ll mod = 0;
    for(ll i = 0; i<s.size(); i++){
        mod = ((mod*10)+(s[i]-'0'))%m;
    }
    return mod;
}
ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
int main (){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    // for(ll i = 0; i<n; i++){
        
    // }
    ll b = reduce(s, n);
    cout<<gcd(n,b);
    return 0;
}