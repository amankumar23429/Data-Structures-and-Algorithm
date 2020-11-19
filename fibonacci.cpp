#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a = 0, b=1;
    int nextTerm;
    for(int i=1; i<=n; i++){
        nextTerm = a+b;
        cout<<a<<endl;
        a=b;
        b=nextTerm;
    }
    return 0;
}
