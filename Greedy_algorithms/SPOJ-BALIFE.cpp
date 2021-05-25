#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

int main(){
    ll n;
    ll arr[10000];
    while(1){
        cin>>n;
        if(n==-1){
            break;
        }
        ll load = 0;
        for(ll i = 0; i<n; i++){
            cin>>arr[i]; 
            load+=arr[i];
        }
        if(load%n!=0){
            cout<<-1<<endl;
            continue;
        }

        load = load/n;
        ll diff = 0;
        ll max_load = 0;

        for(ll i = 0; i<n; i++){
            diff += arr[i]-load;
            max_load = max(max_load, abs(diff));
        }
        cout<<max_load<<endl;
    }
    return 0;
}