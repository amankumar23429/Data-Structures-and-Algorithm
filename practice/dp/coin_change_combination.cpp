#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main (){
    ll n;
    cin>>n;
    ll money;
    cin>>money;
    vector<ll> coins;
    vector<ll> dp(money+1,0);
    for(ll i = 0; i<n; i++){
        ll num;
        cin>>num;
        coins.push_back(num);
    }

    dp[0] = 1;
    for(ll i = 0; i<n; i++){
        ll coin = coins[i];
        for(ll j = coin; j<=money; j++){
            dp[j] += dp[j-coin];
        }
    }

    cout<<dp[money]<<endl;

    return 0;
}