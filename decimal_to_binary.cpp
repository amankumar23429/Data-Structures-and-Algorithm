#include<iostream>
#include<cmath>
using namespace std;

int decimal_to_binary(int num){

    int i = 1;
    while(i<=num){
        i *= 2;
    }
    i /= 2;

    int result = 0;

    while(i>0){
        int x = num / i;
        result = result*10 + x;
        num -= x*i;
        i /= 2;
    }
    cout<<num<<endl;

    return result;

}

int main(){
    int number;
    cin>>number;

    int a = decimal_to_binary(number);

    cout<<a;

    return 0;
}