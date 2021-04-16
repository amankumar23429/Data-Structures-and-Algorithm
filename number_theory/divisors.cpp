#include<iostream>
#include<vector>
using namespace std;

int no_of_divisors(int n){
    int count;
    int ans = 1;

    for(int i = 2; i*i<=n; i++){
        count = 0;
        if(n%i==0){
            while(n%i==0){
                count++;
                n = n/i;
            }
            ans = (count+1)*ans;
        }
    }
    if(n!=1){
        ans = ans*2;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<no_of_divisors(n);
    return 0;
}