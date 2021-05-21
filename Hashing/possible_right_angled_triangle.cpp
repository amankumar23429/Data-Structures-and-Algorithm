#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int find_triangles(vector<pair<int, int>> &v){
    unordered_map<int, int> x_coor;
    unordered_map<int, int> y_coor;

    for(int i = 0; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        if(x_coor.count(x)){
            x_coor[x]++;
        }else{
            x_coor[x] = 1;
        }

        if(y_coor.count(y)){
            y_coor[y]++;
        }
        else{
            y_coor[y] = 1;
        }
    }
    int ans = 0; 
    for(int i = 0; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        
        if(x_coor[x]>1 and y_coor[y]>1){
            ans += (x_coor[x]-1)*(y_coor[y]-1);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    int x,y;
    for(int i = 0; i<n; i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    cout<<find_triangles(v);
    return 0;
}