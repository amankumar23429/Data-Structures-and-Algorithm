#include<iostream>
#include<algorithm>
using namespace std;

int make_change(int *arr, int n, int money){
    int ans = 0;
    while(money>0){
        int idx = upper_bound(arr, arr+n, money)-arr-1;
        money = money - arr[idx];
        ans++;
        cout<<arr[idx]<<" + ";
    }
    cout<<endl;
    return ans;
}

int main(){
    int arr[] = {1,2,5,10,20,50,100,200,500,2000};
    int n = sizeof(arr)/sizeof(int);
    int money;
    cin>>money;
    cout<<make_change(arr, n, money);
}