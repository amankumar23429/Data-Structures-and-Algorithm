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
    int re, rs, cs, ce;
    rs = 0;
    re = row-1;
    cs = 0;
    ce = col-1;
    
    while (rs <= re && cs <= ce){
        for (int i = cs; i <= ce; i++){
            cout << a[rs][i] << " ";
        }
        rs++;

        for (int i = rs; i <= re; i++){
            cout << a[i][ce] << " ";
        }
        ce--;

        for (int i = ce; i >= cs; i--){
            cout << a[re][i] << " ";
        }
        re--;
        
        for (int i = re; i >= rs; i--){
            cout << a[i][cs] << " ";
        }
        cs++;
    }
    return 0;
}
