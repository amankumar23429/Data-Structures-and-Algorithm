#include<iostream>
using namespace std;

int main(){
    // allocation and deallocation is done by compiler
    int x[100] = {0};
    cout<<sizeof(x)<<endl;
    cout<<x<<endl; // written in symbol table and x can not be overwritten, x is a part of read only memory

    int n;
    cin>>n;

    // dynamic allocation
    int *y = new int[n]{0};
    cout<<sizeof(y)<<endl;

    cout<<y<<endl; //variable y is created inside the static memory, it can be overwritten 

    // no change in input 
    for(int i = 0; i<n; i++){
        cin>>y[i];
    }

    for(int i = 0; i<n; i++){
        cout<<y[i]<<endl;
    }

    //free space
    delete [] y;
    return 0;
}
