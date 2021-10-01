#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int fast_expo(int a, int n){
    if(n==0){
        return 1;
    }
    int smaller_ans = fast_expo(a, n/2);
    smaller_ans *= smaller_ans;
    if(n%2!=0){
        smaller_ans *= a;
    }
    return smaller_ans;
}

int main (){
    cout<<fast_expo(2,4);
    return 0;
}