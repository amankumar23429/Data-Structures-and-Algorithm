#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main (){
    ll n;
    cin>>n;
    vector<ll> v;
    ll dp[n+1];
    for(ll i = 0; i<n; i++){
        ll num;
        cin>>num;
        v.push_back(num);
    }
    for(ll i = 0; i<n; i++){
        dp[i] = INT_MAX;
    }

    dp[n] = 0;
    for(int i = n-1; i>=0; i--){
        ll min_num = INT_MAX;
        for(int j = i+1; j<=i+v[i]; j++){
            if(j<=n){
                min_num = min(dp[j], min_num);
            }
        }
        dp[i] = min_num+1;
    }
    cout<<dp[0]<<endl;
    return 0;
}