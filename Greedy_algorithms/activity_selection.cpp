#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second<p2.second;
}

int main(){
    int t,n,s,e;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int, int>> v;
        for(int i = 0; i<n; i++){
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }

        sort(v.begin(), v.end(), compare);
        
        int result = 1;
        int fin = v[0].second;

        for(int i = 1; i<n; i++){
            if(v[i].first>=fin){
                fin = v[i].second;
                result++;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}