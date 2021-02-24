#include<iostream>
#include<climits>
using namespace std;

int maximize_profit(int *weight, int *price, int capac, int n){
    if(n==0 || capac==0){
        return 0;
    }
    int ans = 0;
    int inc,exc;
    inc = exc = INT_MIN;
    if(weight[n-1]<=capac){
        inc = price[n-1] + maximize_profit(weight, price, capac-weight[n-1], n-1);
    }
    exc = maximize_profit(weight, price, capac, n-1);
    ans = max(inc, exc);
    return ans;
}

int main(){

    int w[] = {1,2,3,5};
    int p[] = {40,20,30,100};
    int n = 4;
    int c = 7;

    cout<<maximize_profit(w, p, c, n);
    return 0;
}