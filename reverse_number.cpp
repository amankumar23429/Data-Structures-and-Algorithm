#include<iostream>
using namespace std;
int main(){
    int number, lastNumber;
    cout<<"enter number";
    cin>>number;
    int reverse = 0;

    while(number>0){
        lastNumber = number % 10;
        reverse = reverse*10 + lastNumber;
        number = number/10;
    }
    cout<<"reverse number is "<< reverse;

    return 0;
}