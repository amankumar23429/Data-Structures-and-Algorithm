#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int number;
    cin>>number;
    int i = 0;
    int sum = 0;

    while(number>0){
        int num = number%10;
        sum += pow(2,i)*num;
        number = number/10;
        i++;
    }

    cout<<sum;

    return 0;
}