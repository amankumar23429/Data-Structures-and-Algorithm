#include<iostream>
using namespace std;


int main(){
    int a[100] = {0};
    int n = 0;
    int i = 0;
    int pair_sum = 0;
    
    cin>>n;
    int j = n-1;
    cin>>pair_sum;
    // takes array input
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    while(i<j){
        if(a[i]+a[j]==pair_sum){
            cout<<"pair found and elements are "<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }else if(a[i]+a[j]<pair_sum){
            i++;
        }else{
            j--;
        }
    }
    return 0;
}