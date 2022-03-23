#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int x,y,gcd;
void extended_gcd(ll a, ll b){
    if(b==0){
        gcd = a;
        x = 1;
        y = 0;
        return;
    }
    extended_gcd(b, a%b);
    ll cx = y;
    ll cy = x-(a/b)*y;
    x = cx;
    y = cy;
    return;
}

ll inverse_modulo(ll a, ll m){
    extended_gcd(a,m);
    return (x+m)%m;
}
int main (){
    ll a,b;
    //cin>>a>>b;
    cout<<inverse_modulo(18,7);
    
    return 0;
}