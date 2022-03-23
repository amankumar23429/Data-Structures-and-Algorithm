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
ll n1 = 1000000;
vector<ll> v1(n1+1);
vector<ll> v2(n1+5);
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
    ll cnt = 0;
    v1[0] = 0;
    for(ll i = 1; i<=n1; i++){
        v1[i] = v1[i-1];
        ll product = 1;
        ll sum = 0;
        string temp = to_string(i);
        for(auto p:temp){
            product*=(p-'0');
            sum+=(p-'0');
        }
        if(product%sum==0){
            v1[i]++;
        }
    }
    // v2[0] = v1[n1];
    // for(ll i = n1+1; i<=1000000000000; i++){
    //     // v2[i-n1] = v2[i-n1-1];
    //     // ll product = 1;
    //     // ll sum = 0;
    //     // string temp = to_string(i);
    //     // for(auto p:temp){
    //     //     product*=(p-'0');
    //     //     sum+=(p-'0');
    //     // }
    //     // if(product%sum==0){
    //     //     v2[i-n1]++;
    //     // }
    // }
    test(){
        cnt++;
        ll a,b;
        cin>>a>>b;
        if(b<=n1){
            cout<<"Case #"<<cnt<<": "<<v1[b]-v1[a-1]<<endl;
        }
        else{
            if(a>=n1){
                cout<<"Case #"<<cnt<<": "<<v2[b-n1]-v2[a-n1-1]<<endl;
            }
            else{
                cout<<"Case #"<<cnt<<": "<<v2[b-n1]-v1[a-1]<<endl;
            }
        }
    }
    return 0;
}