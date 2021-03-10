#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

const ll N = 1e5+5;
ll arr[N];

int main(){
    ll testCase;
    cin>>testCase;
    for(ll x = 0; x<testCase; x++){
        ll n, budget;
        cin>>n>>budget;
        for(ll i = 0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        ll ans = 0;
        for(ll i = 0; i<n; i++){
            if(arr[i]<=budget){
                budget -= arr[i];
                ans++;
            }
        }
        cout<<"Case #"<<x+1<<": "<<ans<<endl;
    }
    return 0;
}