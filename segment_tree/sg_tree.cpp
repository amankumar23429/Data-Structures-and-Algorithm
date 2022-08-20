#include<bits/stdc++.h>
using namespace std;

class Sgtree{
    vector<int> seg;
    public:
    Sgtree(int n){
        seg.resize(4*n+1);
    }

    void build(int idx, int low, int high, int arr[]){
        if(low==high){
            seg[idx] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }

    int query(int idx, int low, int high, int l, int r){
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
        return min(left, right);
    }

    void update(int idx, int low, int high, int i, int val){
        if(low==high){
            seg[idx] = val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid) update(2*idx+1, low, mid, i, val);
        else update(2*idx+2, mid+1, high, i, val);
        seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
    }
};

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    Sgtree sg(n);
    sg.build(0, 0, n-1, arr);
    
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l, r;
            cin>>l>>r;
            cout<<sg.query(0, 0, n-1, l, r)<<endl;
        }
        else{
            int i, val;
            cin>>i>>val;
            sg.update(0, 0, n-1, i, val);
        }
    }
}

void solve1(){
    int n1;
    cin>>n1;
    int arr[n1];
    for(int i = 0; i<n1; i++) cin>>arr[i];
    
    Sgtree sg1(n1);
    sg1.build(0, 0, n1-1, arr);

    int n2;;
    cin>>n2;
    int arr2[n2];
    for(int i = 0; i<n2; i++) cin>>arr2[i];
    Sgtree sg2(n2);
    sg2.build(0, 0, n2-1, arr2);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l1, r1, l2, r2;
            cin>>l1>>r1>>l2>>r2;
            int min1 = sg1.query(0, 0, n1-1, l1, r1);
            int min2 = sg2.query(0, 0, n2-1, l2, r2);
            cout<<min(min1, min2)<<endl;
        }
        else{
            int arr_no, i, val;
            cin>>arr_no>>i>>val;
            if(arr_no==1){
                sg1.update(0, 0, n1-1, i, val);
            }
            else{
                sg2.update(0, 0, n2-1, i, val);
                arr2[i] = val;
            }
        }
    }
}
int main(){
    solve();
    return 0;
}
