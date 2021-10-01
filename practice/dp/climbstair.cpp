#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long int
#define MOD 1000000007
#define endl "\n"
#define test() ll t; cin>>t; while(t--)
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

bool compare(ll a,ll b){
    return a<b;
}

int total_ways(int n, int *dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]>0){
        return dp[n];
    }
    int small_ans1 = total_ways(n-1, dp);
    int small_ans2 = total_ways(n-2, dp);
    int small_ans3 = total_ways(n-3, dp);

    int ans = small_ans1+small_ans2+small_ans3;
    dp[n] = ans;
    return ans;
}

int total_ways_tab(int n){
    int dp[n+1] = {0};
    dp[0] = 1;
    
    for(int i = 1; i<=n; i++){
        if(i==1){
            dp[i] = dp[i-1];
        }
        else if(i==2){
            dp[i] = dp[i-1] + dp[i-2];
        }
        else{
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
    }
    return dp[n];
}

int main (){
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //test(){
        ll n;
        cin>>n;
        int dp[n+1] = {0};
        
        cout<<total_ways(n, dp)<<endl;
        cout<<total_ways_tab(n);
    //}
    return 0;
}