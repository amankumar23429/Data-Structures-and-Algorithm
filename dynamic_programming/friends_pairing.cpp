#include<bits/stdc++.h>
using namespace std;

int dp[10001];
int NumberOfWays(int N){
    if(N==1 or N==0){
        return 1;
    }
    if(dp[N]!=-1){
        return dp[N];
    }
    int dp[N] = {-1};
    int ans = NumberOfWays(N-1) + (N-1)*NumberOfWays(N-2);
	return dp[N] = ans;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<NumberOfWays(n);
    return 0;
}


