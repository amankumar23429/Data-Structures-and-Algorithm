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

bool isSorted(int a[], int n){
	if(n==1){
		return true;
	}
	if(a[0]<a[1]){
		return isSorted(a+1,n-1);
	}
	return false;
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
		int a[100];
		for(ll i = 0; i<n; i++){
			cin>>a[i];
		}
		cout<<isSorted(a,n);
	//}
	return 0;
}