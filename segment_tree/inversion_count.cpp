#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void build(int idx, int low, int high, int arr[], int seg[]){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*idx+1, low, mid, arr, seg);
    build(2*idx+2, mid+1, high, arr, seg);
    seg[idx] = seg[idx*2+1] + seg[idx*2+2];
}


void update(int idx, int low, int high, int i, int val, int seg[]){
    if(low==high){
        seg[idx] += val;
        return;
    }
    int mid = (low+high)/2;
    if(i<=mid){
        update(2*idx+1, low, mid, i, val, seg);
    }
    else{
        update(2*idx+2, mid+1, high, i, val, seg);
    }
    seg[idx] = seg[idx*2+1] + seg[idx*2+2];
}

int query(int idx, int low, int high, int l, int r, int seg[]){
    // no overlap
    // l r low high or low high l r
    if(r<low or high<l) return 0;

    // complete overlap
    // l low high r
    if(low>=l and high<=r) return seg[idx];

    // partial overlap
    int mid = (low+high)/2;
    int left = query(2*idx+1, low, mid, l, r, seg);
    int right = query(2*idx+2, mid+1, high, l, r, seg);
    return left+right;
}

int main (){
    ll t;
    cin>>t;
    while(t--){
        //cout<<t<<endl;
        ll n;
        cin>>n;
        int arr[n];
        int maxi = -1;
        for(ll i = 0; i<n; i++){
            cin>>arr[i];
            maxi = max(maxi, arr[i]);
        }
        maxi++;
        int freq[maxi];
        memset(freq, 0, sizeof(freq));
        for(ll i = 0; i<n; i++){
            freq[arr[i]]++;
        }
        int seg[4*maxi]; 
        build(0, 0, maxi-1, freq, seg);
        int ans = 0;
        for(ll i = 0; i<n; i++){
            freq[arr[i]]--;
            update(0, 0, maxi-1, arr[i], -1, seg);
            ans += query(0, 0, maxi-1, 1, arr[i]-1, seg);
        }
        cout<<ans<<endl;
    }
    return 0;
}