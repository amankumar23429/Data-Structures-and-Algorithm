#include<iostream>
using namespace std;

float square_root(int n, int p = 2){
    int s = 0;
    int e = n-1;
    float ans = -1;

    while(s<=e){
        int mid = (s+e)/2;
        if(mid * mid == n){
            return mid;
        }
        else if(mid * mid < n){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        
    }

    float dec = 0.1;

    for (int i = 1; i<=p; i++){
        while(ans*ans <= n){
            ans += dec;
        }
        ans = ans - dec;
        dec = dec / 10;
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
   
    cout<<square_root(n);
    
    return 0;

}