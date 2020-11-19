#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int number;
    cout<<"enter number";
    cin>>number;

    int isPrime = 1;
    for (int i=2; i<=sqrt(number); i++){
        if(number%i==0){
            isPrime = 0;
        }
    }
    cout<<sqrt(number);
    if(isPrime==1){
        cout<<"number "<< number <<" is prime";
    }else{
        cout<<"number "<< number <<" is not prime";
    }
    return 0;
}