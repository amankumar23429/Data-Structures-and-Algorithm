#include<iostream>
using namespace std;

int main(){
    int a[100][100]={0};
    int m,n;
    cin>>m>>n;
    int value = 1;
    int start_row = 0;
    int start_col = 0;
    int end_col = n-1;
    int end_row = m-1;

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = value;
            value++;
        }
    }

    while(start_row <= end_row and start_col <= end_col){
        
        for (int i = start_col; i<=end_col; i++){
            cout<<a[start_row][i]<<" "; 
        }
        start_row++;

        for (int i = start_row; i<=end_row; i++){
            cout<<a[i][end_col]<<" ";  
        }
        end_col--;

        if(start_row<end_row){
            for (int i = end_col; i>=start_col; i--){
                cout<<a[end_row][i]<<" ";
            }
            end_row--;
        }

        if(start_col<end_col){
            for (int i = end_row; i>=start_row; i--){
                cout<<a[i][start_col]<<" ";
            }
            start_col++;
        }
    }

    return 0;
}