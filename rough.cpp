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
ll gcd(ll a, ll b){
    return b==0?a:gcd(b, a%b);
}
ll dp[1000005];
ll toint(string s){
    ll a = 1;
    ll ans = 0;
    for(int i = 0; i<s.size(); i++){
        ans= ans*10 + (s[i]-'0');
    }
    return ans;
}
ll reverse(ll n, ll a){
    string s = to_string(n);
    string s1 = "";
    s1 += s.substr(1,s.size()-1);
    s1 += s[0];
    return toint(s1);
}

// ll counts(ll n, ll a){
//     if(n==1){
//         return 1;
//     }
//     if(n%10==0 and n%a!=0){
//         return -1;
//     }
//     ll ans1 = 0;
//     ll ans2 = 0;
//     if(n%a==0){
//         ll temp = counts(n/a, a);
//         if(temp!=-1){
//             ans2 = temp+1;
//         }
//         else{
//             ans2 = -1;
//         }
//     }
//     if(n%10!=0){
//         ll temp = counts(reverse(n,a),a);
//         if(temp!=-1){
//             ans1 = temp+1;
//         }
//         else{
//             ans2 = -1;
//         }
//     }
    
//     if(ans1!=-1 and ans2!=-1){
//         return min(ans1, ans2);
//     }
//     else if(ans1==-1 and ans2==-1){
//         return -1;
//     }
//     else if(ans2==-1){
//         return ans1;
//     }
//     else{
//         return ans2;
//     }
// }

ll counts(ll n, ll a, ll dp[]){
    if(n==1){
        return 0;
    }
    // if(dp[n]!=0){
    //     return dp[n];
    // }
    string s = to_string(n);
    bool flag = false;
    ll ans = INT_MAX;
    for(int i = 0; i<s.size(); i++){
        string s1 = "";
        s1+=s.substr(i, s.size()-i);
        s1+=s.substr(0, i);
        //cout<<s1<<endl;
        ll num = toint(s1);
        if(num%a==0){
            flag = true;
            ll temp = counts(num/a,a, dp);
            if(temp!=-1){
                cout<<num<<endl;
                
                //ans = min(ans, temp+1+i);
                break;
            }
        }
    }
    if(flag==false or ans==INT_MAX){
        return -1;
    }
    else{
        return dp[n] = ans;
    }
}
 
int main (){
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    //test(){
        ll a,n;
        cin>>a>>n;
        
        memset(dp, 0, sizeof(dp));
        
        //cout<<reverse(n,a);
        cout<<counts(n,a, dp);
    //}
    return 0;
}