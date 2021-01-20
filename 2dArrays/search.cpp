#include<iostream>
using namespace std;

int main(){
    int row,col;
    cin >> row >> col;
    int a[row][col];

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> a[i][j];
        }
    }
    int key;
    cin >> key;
    bool flag = false;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(a[i][j] == key){
                cout << "element is found in matrix at" << i <<" " << j;
                flag = true;
                break;
            }
        }
    }
    if (flag == false){
        cout << "element is not found in matrix";
    }

    return 0;
}
