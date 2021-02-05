#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    int min_index = INT_MAX;
    cin>>n;
    int arr[n];
    int index_arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i<n; i++){
        index_arr[i] = -1;
    }

    for(int i = 0; i<n; i++){
        if(index_arr[arr[i]]<0){
            index_arr[arr[i]] = i;
        }else{
            min_index = min(min_index, index_arr[arr[i]]);
        }
    }

    if(min_index == INT_MAX){
        cout<<"-1"<<endl;
    }else{
        cout<<min_index+1<<endl;
    }
    
    return 0;
}