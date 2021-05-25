#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

int main(){
    int n, diff;
    cin>>n>>diff;
    vector<int> v;
    int no;
    for(int i = 0; i<n; i++){
        cin>>no;
        v.push_back(no);
    }
    if(n>1){
        int ans = 0;
        sort(v.begin(), v.end());
        int i = 1;
        for(i = 1; i<n; i++){
            if(v[i]-v[i-1]<=diff){
                ans++;
                i++;   
            }
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
    
    return 0;
}