#include<iostream>
using namespace std;

int main(){
    
    int n,no;
    cin>>n;
    int arr[64] = {0};
    
    for(int i=0; i<n; i++){
       cin>>no;
       int j = 0;
       while(no>0){
           arr[j] += (1&no);
           no = no>>1;
           j++;
       }
    }

    int p = 1;
    int x = 0;
    int ans = 0;

    for(int i=0; i<64; i++){
       x = arr[i]%3;
       ans += p*x;
       p = p*2;
    }
    cout<<ans;
    
    return 0;
}