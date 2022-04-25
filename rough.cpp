#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int turnPigeons(string A){
    int ans = 0;
    char prev = 'a';
    int cnt = 0;
    int n = A.size();
    vector<int> r(n, 0);
    vector<int> l(n, 0);
    for(int i = 0; i<A.size(); i++){
        if(i>0){
            r[i] = r[i-1];
        }
        if(A[i]=='R'){
            r[i]++;
        }
    }
    for(int i = n-1; i>=0; i--){
        if(i!=n-1){
            l[i] = l[i+1];
        }
        if(A[i]=='L'){
            l[i]++;
        }
    }
    int min_num = 100000000;
    for(int i = 0; i<A.size(); i++){
        //cout<<l[i]<<" "<<r[i]<<endl;
        min_num = min(min_num, l[i]+r[i]-1);
    }
    // min_num = min(r[n-1], min_num);
    // min_num = min(l[0], min_num);
    
    return min_num;
}
int main (){
    string s;
    cin>>s;
    cout<<turnPigeons(s);
    return 0;
}