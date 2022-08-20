#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void build(int idx, int low, int high, int orr, int arr[], int seg[]){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*idx+1, low, mid, !orr, arr, seg);
    build(2*idx+2, mid+1, high, !orr, arr, seg);

    if(orr){
        seg[idx] = seg[idx*2+1] | seg[idx*2+2];
    }
    else{
        seg[idx] = seg[idx*2+1] ^ seg[idx*2+2];
    }
}


void update(int idx, int low, int high, int i, int val, int seg[], int orr){
    if(low==high){
        seg[idx] = val;
        return;
    }
    int mid = (low+high)/2;
    if(i<=mid){
        update(2*idx+1, low, mid, i, val, seg, !orr);
    }
    else{
        update(2*idx+2, mid+1, high, i, val, seg, !orr);
    }

    if(orr){
        seg[idx] = seg[idx*2+1] | seg[idx*2+2];
    }
    else{
        seg[idx] = seg[idx*2+1] ^ seg[idx*2+2];
    }
}

int main (){
    ll n, q;
    cin>>n>>q;
    int ele = pow(2,n);
    int arr[ele];
    for(ll i = 0; i<ele; i++){
        cin>>arr[i];
    }
    int seg[4*ele+1];
    if(n%2==0){
        build(0, 0, ele-1, 0, arr, seg);
    }
    else{
        build(0, 0, ele-1, 1, arr, seg);
    }

    // for(auto p:seg){
    //     cout<<p<<" ";
    // }
    // cout<<endl;
    
    while(q--){
        int idx, val;
        cin>>idx>>val;
        update(0, 0, ele-1, idx-1, val, seg, n%2);
        cout<<seg[0]<<endl;
    }

    return 0;
}