#include<iostream>
using namespace std;

int main(){
    
    int n,no;
    cin>>n;
    int arr[n];
    int all_xor = 0;
    for(int i=0; i<n; i++){
        cin>>no;
        all_xor = all_xor^no;
        arr[i] = no;
    }

    int temp = all_xor;
    int pos = 0;

    while((temp&1)==0){
        pos++;
        temp = temp>>1;
    }

    int a = 0;
    int b = 0;
    int mask = 1<<pos;

    for(int i = 0; i<n; i++){
        if(mask&arr[i]){
            a = a^arr[i];
        }
    }

    b = a^all_xor;

    cout<<min(a,b)<<" "<<max(a,b);

    return 0;
}