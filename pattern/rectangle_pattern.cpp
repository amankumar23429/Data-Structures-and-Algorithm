#include<iostream>
using namespace std;
int main(){
    int row, column = 0;
    cout<<"enter row and column";
    cin>>row>>column;

    for (int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}