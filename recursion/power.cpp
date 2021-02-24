#include<iostream>
using namespace std;

int pow(int a, int n){
    if(n==0){
        return 1;
    }
    return a*pow(a,n-1);
}

int fast_pow(int a, int n){
    if(n==0){
        return 1;
    }

    int smaller_ans = fast_pow(a, n/2);
    smaller_ans *= smaller_ans;
    if(n%2==0){
        return smaller_ans;
    }
    
    return a*smaller_ans;
}



int main(){
    int a,n;
    cin>>a>>n;
    //cout<<pow(a,n);
    cout<<fast_pow(a,n);
    return 0;
}