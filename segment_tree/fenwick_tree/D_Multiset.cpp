#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int maxi = 1e6+5;
int fen[maxi];

void update(int i, int num, int n){
    while(i<=n){
        fen[i] += num;
        i = i + (i&(-i));
    }
}

int sum(int i){
    int ans = 0;
    while(i>0){
        ans+=fen[i];
        i = i-(i&(-i));
    }
    return ans;
}

int find(int k, int n){
    int curr = 0, prev_sum = 0, ans = 0;
    for(int i = log2(n); i>=0; i--){
        if(curr+(1<<i)<=n and fen[curr+(1<<i)]+prev_sum<k){
            curr += 1<<i;
            prev_sum += fen[curr];
        }
    }
    return curr+1;
}

int main (){
    #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll n, q;
    cin>>n>>q;

    for(ll i = 0; i<n; i++){
        int num;
        cin>>num;
        update(num, 1, n);
    }

    while(q--){
        int x;
        cin>>x;
        if(x>0){
            update(x, 1, n);
        }
        else{
            x = -1*x;
            int idx = find(x, n);
            update(idx, -1, n);
        }
    }
    int total = sum(n);
    if(total==0){
        cout<<0<<endl;
    }
    else{
        for(int i = 1; i<=n; i++){
            if(sum(i)>0){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
