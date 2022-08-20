#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void update(int i, int add, int n, int fen[]){
    while(i<=n){
        fen[i]+=add;
        i = i + (i&(-i));
    }
}

int sum(int i, int fen[]){
    int ans = 0;
    while(i>0){
        ans+=fen[i];
        i = i-(i&(-i));
    }
    return ans;
}

int rangeSum(int l, int r, int fen[]){
    return sum(r, fen) - sum(l-1, fen);
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
    //cout<<sum(12, fen)<<endl;
    cout<<rangeSum(2, 5, fen);
    
    return 0;
}