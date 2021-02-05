#include<iostream>
using namespace std;

int increment(int a){
    a = a+1;
    return a;
}

int increment1(int *ptr){
    *ptr = *ptr+1;
    return *ptr;
}

int main(){
    int a = 5;
    cout<<"initial value of a is "<< a<<endl;
    increment(a);

    cout<<"final value of a is "<< a<<endl;

    increment1(&a);

    cout<<"after using call by reference final value of a is "<< a;


    return 0;
}