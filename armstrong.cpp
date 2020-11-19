#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    int original_num = n;
    while(n>0){
        int last = n%10;
        sum = sum + (last*last*last);
        n = n/10;
        cout<<sum<<endl;
    }
    if (original_num==sum){
        cout<<" number is armstrong ";
    }else{
        cout<<" number is not armstrong";
    }
    return 0;
}