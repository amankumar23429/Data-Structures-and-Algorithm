#include<iostream>
#include<vector>
using namespace std;

void buildHeap(vector<int> &v){
    for(int i = 2; i<v.size(); i++){
        int idx = i;
        int parent = i/2;
        while(idx>1 and v[parent]<v[idx]){
            swap(v[parent], v[idx]);
            idx = parent;
            parent = parent/2;
        }
    }
}

void print(vector<int> v){
    for(int i = 1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4}; 
    print(v);
    buildHeap(v);
    print(v);
    return 0;
}