#include<iostream>
using namespace std;

int main(){
    int **arr;
    int r,c;
    cin>>r>>c;

    arr = new int *[r];

    for (int i = 0; i<r; i++){
        arr[i] = new int[c];
    }

    int value = 1;
    for(int i = 0; i<r; i++){
        for (int j =0; j<c; j++){
            arr[i][j] = value;
            value++;
        }
    }

    for(int i = 0; i<r; i++){
        for (int j =0; j<c; j++){
            cout<<arr[i][j]<<" ";
            value++;
        }
        cout<<endl;
    }
    return 0;
}