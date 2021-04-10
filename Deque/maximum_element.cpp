#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n; 
    int arr[100000];
    int k;

    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cin>>k;
    
    deque<int> q(k);

    int i;
    for(i = 0; i<k; i++){
        while(!q.empty() && (arr[i]>arr[q.back()])){ 
            q.pop_back();
        }
        q.push_back(i);
    }
    
    for(; i<n; i++){
        cout<<arr[q.front()]<<" ";

        while(!q.empty() && q.front()<=i-k){
            q.pop_front();
        }

        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.back()];
    return 0;
}
