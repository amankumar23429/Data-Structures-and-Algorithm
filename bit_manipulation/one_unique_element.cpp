#include<iostream>
using namespace std;

int main(){
    int n;
    int ans = 0;
    int no;

    cin>>n;

    for(int i = 0; i<n; i++){
       cin>>no;
       ans = ans^no;
    }

    cout<<ans;

    return 0;
}