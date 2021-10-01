#include<iostream>
using namespace std;

#define ll long long
int arr[1000005] = {0};
int cs[1000005] = {0};

void prime_sieve(int *arr){
    
    for(ll int i = 3; i<=1000000; i+=2){
        arr[i] = 1;
    }

    for(ll int i = 3; i<=1000000; i+=2){
        if(arr[i]==1){
            for(ll int j = i*i; j<=1000000; j+=i){
                arr[j] = 0;
            }
        }
    }
    arr[2] = 1;
    arr[0] = arr[1] = 0;
}

int main(){
    prime_sieve(arr);
    int num = 0;
    for(int i = 1; i<=1000000; i++){
        num += arr[i];
        cs[i] = num;
    }

    int q;
    cin>>q;
    for(int i = 0; i<q; i++){
        int a,b;
        cin>>a>>b;
        cout<<cs[b]-cs[a-1]<<endl;
    }
    return 0;
}