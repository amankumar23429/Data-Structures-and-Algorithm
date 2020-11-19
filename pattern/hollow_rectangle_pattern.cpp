#include<iostream>
using namespace std;
int main(){
    int row, column = 0;
    cout<<"enter row and column";
    cin>>row>>column;

    for (int i=1; i<=row; i++){
        for (int j=1; j<=column; j++){
            if (i==row || i==1 || j==1 || j==column){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}