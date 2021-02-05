#include<iostream>
using namespace std;

int main(){
    int *ptr;

    int x = 10;
    ptr = &x;
    cout<<ptr<<endl;

    char c = 'a';

    cout<<&c<<endl; // this do not give give the address this is a exception

    cout<<(void *)&c<<endl;

    cout<<*ptr<<endl;  // dereference operator
    cout<<*(&x)<<endl;

    int **y = &ptr;
    cout << y<<endl;
    cout << **y;

    return 0;
}