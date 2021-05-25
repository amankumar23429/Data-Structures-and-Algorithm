#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        ll rank;
        vector<ll> v;
        for(ll i = 0; i<n; i++){
            cin>>s>>rank;
            v.push_back(rank);
        }
        sort(v.begin(), v.end());

        ll ans = 0;
        for(ll i = 0; i<n; i++){
            ans += abs(v[i]-(i+1)); 
        }
        cout<<ans<<endl;
    }
    return 0;
}