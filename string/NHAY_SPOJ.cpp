// spoj problem
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long int
#define MOD 1000000009
#define endl "\n"
#define test() ll t; cin>>t; while(t--)
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

const int n = 1e6+5;

ll prefix[n], power[n];

bool compare(ll a,ll b){
    return a<b;
}
ll gcd(ll a, ll b){
    return b==0?a:gcd(b, a%b);
}
 
int main (){
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    power[0] = 1;
    ll p = 1;
    for(ll i = 1; i<=1e6+2; i++){
        p = (p*31)%MOD;
        power[i] = p;
    }
    ll n, m;
    while(cin>>m){
        string s1, s2;
        cin>>s2>>s1;
        int ans = 0;
        ll n = s1.size();
        
        if(m>n){
            cout<<endl;
        }
        else{
            prefix[0] = (s1[0]-'a')+1;
            ll patt_hash = 0;

            for(ll i = 1; i<n; i++){
                prefix[i] = (prefix[i-1]+(s1[i]-'a'+1)*power[i])%MOD;
            }

            for(ll i = 0; i<m; i++){
                patt_hash = (patt_hash+((s2[i]-'a'+1)*power[i]))%MOD;
            }

            for(ll i = 0; i<=n-m; i++){
                if(s1[i]==s2[0]){
                    if(i>0){
                        ll temp = (prefix[i+m-1]-prefix[i-1]+MOD)%MOD;
                        if(temp==(patt_hash*power[i])%MOD){
                            cout<<i<<endl;
                            ans++;
                        }
                    }
                    else{
                        if(prefix[i+m-1]==(patt_hash*power[i])%MOD){
                            cout<<i<<endl;
                            ans++;
                        }
                    }
                }
            }
            if(ans==0){
                cout<<endl;
            }
        }
    }
    return 0;
}