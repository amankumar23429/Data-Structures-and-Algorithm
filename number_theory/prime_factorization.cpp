#include<iostream>
#include<vector>
using namespace std;

void printFactors(int n){
    vector<pair<int, int>> factors;
    int count;

    for(int i = 2; i*i<=n; i++){
        count = 0;
        if(n%i==0){
            while(n%i==0){
                count++;
                n = n/i;
            }
            factors.push_back(make_pair(i,count));
        }
    }
    if(n!=1){
        factors.push_back(make_pair(n,1));
    }

    for(auto x:factors){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    printFactors(n);
    return 0;
}