#include<iostream>
using namespace std;

int power(int a , int b){
    int ans = 1;
    while(b>0){
        if (b&1){
            ans = ans * a;
        }
        b = b>>1;
        a = a*a;
    }
    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;

    cout<<power(a,b);
    return 0;
}