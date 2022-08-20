#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class St{
    vector<int> seg, lazy;

    public:
    St(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int idx, int low, int high, int arr[]){
        if(low==high){
            seg[idx] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }

    void update(int idx, int low, int high, int l, int r, int val){
        if(lazy[idx]!=0){
            seg[idx] += lazy[idx];
            if(low!=high){
                lazy[2*idx+1] = lazy[idx];
                lazy[2*idx+2] = lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap
        if(high<l or r<low){
            return;
        }

        // complete overlap
        if(l<=low and r>=high){
            seg[idx] += val;
            if(low!=high){
                lazy[2*idx+1] += val;
                lazy[2*idx+2] += val;
            }
            return;
        }

        // partial overlap
        int mid = (low+high)/2;
        update(2*idx+1, low, mid, l, r, val);
        update(2*idx+2, mid+1, high, l, r, val);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
    
    int query(int idx, int low, int high, int l, int r){
        if(lazy[idx]!=0){
            seg[idx] += lazy[idx];
            if(low!=high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap
        // l r low high or low high l r
        if(r<low or high<l) return INT_MAX;

        // complete overlap
        // l low high r
        if(low>=l and high<=r) return seg[idx];

        // partial overlap
        int mid = (low+high)/2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);
        return min(left,right);
    }
};

int main (){
    int n;
    cin>>n;
    int arr[n];
    for(ll i = 0; i<n; i++){
        cin>>arr[i];
    }
    St st(n);
    st.build(0, 0, n-1, arr);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l, r;
            cin>>l>>r;
            cout<<st.query(0, 0, n-1, l, r)<<endl;
        }
        else{
            int l, r, val;
            cin>>l>>r>>val;
            st.update(0, 0, n-1, l, r, val);
        }
    }
    return 0;
}