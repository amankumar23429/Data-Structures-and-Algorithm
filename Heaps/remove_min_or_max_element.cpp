#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b){
        if(minHeap){
            return a<b;
        }
        return a>b;
    }

    void heapify(int idx){
        int left = idx*2;
        int right = left+1;
        int min_index = idx;
        int last = v.size()-1;

        if(left<=last && compare(v[left], v[idx])){
            min_index = left;
        }
        if(right<=last && compare(v[right], v[min_index])){
            min_index = right;
        }
        if(min_index!=idx){
            swap(v[idx], v[min_index]);
            heapify(min_index);
        }

    }

    public:
    Heap(bool type = true,int default_size = 10){
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type; 
    }

    void push(int d){
        v.push_back(d);
        int index = v.size()-1;
        int parent = index/2;

        while(index>1 and compare(v[index], v[parent])){
            swap(v[index], v[parent]);
            index = parent;
            parent = parent/2;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){
        int last = v.size()-1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty(){
        return v.size()==1;
    }
};

int main(){
    Heap h(false);
    int n;
    cin>>n;
    int no;
    for(int i = 0; i<n; i++){
        cin>>no;
        h.push(no);
    }

    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    
    return 0;
}