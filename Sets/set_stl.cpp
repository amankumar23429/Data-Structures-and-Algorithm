#include<iostream>
#include<set>
using namespace std;

int main(){
    int arr[] = {10, 20, 11, 9, 8, 11, 10};
    int n = sizeof(arr)/sizeof(int);
    set<int> s;
    
    for(int i = 0; i<n; i++){
        s.insert(arr[i]);
    }

    for(auto x:s){
        cout<<x<<" ";
    }
    cout<<endl;

    // s.erase(value to be deleted)
    s.erase(10);

    // s.erase(iterator pointing to the value to be deleted)
    auto it = s.find(11);
    s.erase(it);

    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout<<*it<<" ";
    }
    return 0;
}