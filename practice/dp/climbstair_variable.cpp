#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long int
#define MOD 1000000007
#define endl "\n"
#define test() ll t; cin>>t; while(t--)
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

bool compare(ll a,ll b){
    return a<b;
}
int main (){
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    //test(){
        ll n;
        cin>>n;
        vector<ll> v;
        for(ll i = 0; i<n; i++){
            ll num;
            cin>>num;
            v.push_back(num);
        }

        ll dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        for(ll i = n-1; i>=0; i--){
            for(ll j = 1; j<=v[i] && i+j<n+1; j++){
                dp[i] += dp[i+j];
            }
        }
        cout<<dp[0]<<endl;
    //}
    return 0;
}