#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n,s;
    //int min_index = INT_MAX;
    cin>>n>>s;
    int arr[n];
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int i = 0, j = 0, sum = 0;
    while(j<n){
        sum += arr[j];
        
        while(sum>s){
            sum -= arr[i];
            i++;
        }
        if(sum==s){
            cout<<i+1<<" "<<j+1<<endl;
            break;
        }
        j++;
    }

    if(sum!=s){
        cout<<"not found"<<endl;
    }
    return 0;
}