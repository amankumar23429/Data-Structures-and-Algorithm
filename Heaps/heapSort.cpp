#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &v, int idx, int size){
    int left = 2*idx;
    int right = left+1;
    int min_index = idx;
    int last = size-1;

    if(left<=last and v[idx]<v[left]){
        min_index = left;
    }
    if(right<=last and v[right]>v[min_index]){
        min_index = right;
    }
    if(min_index!=idx){
        swap(v[min_index], v[idx]);
        heapify(v,min_index, size);
    }
}

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

void heapsort(vector<int> &v){
    buildHeap(v);
    int n = v.size();

    while(n>1){
        swap(v[1], v[n-1]);
        n--;
        heapify(v, 1, n);
    }
}

int main(){
    vector<int> v; 
    v.push_back(-1);
    int n;
    cin>>n;

    int num;
    for(int i = 0; i<n; i++){
        cin>>num;
        v.push_back(num);
    }

    print(v);
    heapsort(v);
    print(v);
    return 0;
}