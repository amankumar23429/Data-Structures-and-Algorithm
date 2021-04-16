#include<iostream>
using namespace std;

void prime_sieve(int *arr, int n){
    for(int i = 3; i<=n; i+=2){
        arr[i] = 1;
    }

    for(int i = 3; i<=n; i+=2){
        if(arr[i]==1){
            for(int j = i*i; j<=n; j+=i){
                arr[j] = 0;
            }
        }
    }
    arr[2] = 1;
    arr[0] = arr[1] = 0;

}

int main(){
    int n;
    cin>>n;
    int arr[n+1] = {0};
    prime_sieve(arr, n);

    for(int i = 0; i<=n; i++){
        if(arr[i] == 1){
            cout<<i<<" ";
        }
    }
    
    return 0;
}