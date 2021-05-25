#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.first>p2.first;;
}
int main(){
    int t, n, d, f, D, F;
    cin>>t;
    while(t--){ 
        cin>>n;
        vector<pair<int,int>> v;
        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            cin>>d>>f;
            v.push_back(make_pair(d,f));
        }
        sort(v.begin(), v.end(), compare);
        cin>>D>>F;

        for(int i = 0; i<n; i++){
            v[i].first = D-v[i].first;
        }

        int x = 0;
        int prev = 0;
        int flag = 0;
        int ans = 0;

        while(x<n){
            if(F>=v[x].first-prev){
                F = F-(v[x].first-prev);
                prev = v[x].first;
                pq.push(v[x].second);
                x++;
            }
            else{
                if(pq.empty()){
                    flag = 1;
                    break;
                }
                F += pq.top();
                pq.pop();
                ans++;
            }
        }
        if(flag){
            cout<<-1<<endl;;
        }
        else{
            D = D-v[n-1].first;
            while(F<D){
                if(pq.empty()){
                    cout<<-1<<endl;
                    break;
                }
                F+= pq.top();
                pq.pop();
                ans++;
            }
            if(F>=D){
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}