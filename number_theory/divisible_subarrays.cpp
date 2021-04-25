#include<iostream>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        ll freq[n+5] = {0};
        freq[0] = 1;
        ll sum = 0;
        for(int i = 0; i<n; i++){
            cin>>arr[i];
            sum+=arr[i];
            sum %= n;
            sum = (sum+n)%n;
            freq[sum]++;
        }
        ll ans = 0;
        for(int i = 0; i<n; i++){
            ll m = freq[i];
            ans += (m * (m-1)) / 2;
        }
        cout<<ans<<endl;
    
    }
    
    return 0;
}