#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

int main(){
    vector<vector<int>> arr{{10, 20, 30, 40},
                            {15, 25, 35, 45}, 
                            {24, 29, 37, 48}, 
                            {32, 33, 39, 50}}; 
    
    priority_queue<node, vector<node>, greater<node>> pq;
    int k ;
    cin>>k;
    pq.push({arr[0][0], {0,0}});
    if(k<=(arr.size()*arr[0].size())){
        for(int i = 0; i<k-1; i++){
            node current = pq.top();
            pq.pop();
            int element = current.first;
            int x = current.second.first;
            int y = current.second.second;
            int next = pq.top().first;
            
            if(!pq.empty()){
                while(element==next){
                    pq.pop();
                    next = pq.top().first;
                }
            }
            
            if(x+1<arr.size()){
                pq.push({arr[x+1][y], {x+1,y}});
            }
            if(y+1<arr[x].size()){
                pq.push({arr[x][y+1], {x,y+1}});
            }   
        }
        cout<<pq.top().first<<endl;
    }
    else{
        cout<<"enter valid index";
    }
    
    return 0;
}