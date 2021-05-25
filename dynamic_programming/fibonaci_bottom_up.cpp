#include<iostream>
using namespace std;

int fib(int n){
    int arr[n+1] = {0};
    arr[1] = 1;
    for(int i = 2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int fiboSpaceOpt(int n){
    if(n==0 or n==1){
        return n;
    }
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    cout<<fiboSpaceOpt(n);
    return 0;
}