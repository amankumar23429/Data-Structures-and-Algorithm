#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &v, int idx){
    int left = 2*idx;
    int right = left+1;
    int min_index = idx;
    int last = v.size()-1;

    if(left<=last and v[idx]<v[left]){
        min_index = left;
    }
    if(right<=v.size() and v[right]>v[min_index]){
        min_index = right;
    }
    if(min_index!=idx){
        swap(v[min_index], v[idx]);
        heapify(v,min_index);
    }
}

void buildHeapOptimized(vector<int> &v){
    for(int i = (v.size()-1)/2; i>=1; i--){
        heapify(v,i);
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
    buildHeapOptimized(v);
    print(v);
    return 0;
}