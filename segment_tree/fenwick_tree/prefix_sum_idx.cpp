#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void update(int i, int add, int n, int fen[]){
    while(i<=n){
        fen[i]+=add;
        i = i + (i&(-i));
    }
}

int prefix_sum_idx(int fen[], int n, int k){
    int curr = 0, ans = 0, prev_sum = 0;
    for(int i = log2(n); i>=0; i--){
        if(fen[curr+(1<<i)]+prev_sum<k){
            curr = curr+(1<<i);
            prev_sum+=fen[curr];
        }
    }
    return curr+1;
}

int main (){
    ll n;
    cin>>n;
    int arr[n+1];
    arr[0] = 0;
    for(ll i = 1; i<=n; i++){
        cin>>arr[i];
    }
    int fen[n+1];
    memset(fen, 0, sizeof(fen));
    for(int i = 1; i<=n; i++){
        update(i, arr[i], n, fen);
    }
    cout<<prefix_sum_idx(fen, n, 1);
    
    return 0;
}