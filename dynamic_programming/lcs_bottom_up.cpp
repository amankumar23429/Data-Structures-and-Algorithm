#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int lcs_bottom_up(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i = n1-1; i>=0; i--){
        for(int j = n2-1; j>=0; j--){
            dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            if(s1[i]==s2[j]){
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]) + 1;
            }
        }
    }
    return dp[0][0];
}

int main(){
    string s1 = "ABCD";
    string s2 = "ABEDG";
    cout<<lcs_bottom_up(s1, s2);
    return 0;
}