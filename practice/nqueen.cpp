#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
    int x = i;
    int y = j;
    while(x>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
    }
    x = i; 
    y = j;
    while(x>=0 and y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    x = i;
    y = j;
    while(x>=0 and y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    return true;
}

void nQueen(int board[][10], int i, int n){
    if(i==n){
        for(int x = 0; x<n; x++){
            for(int j = 0; j<n; j++){
                cout<<board[x][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    for(int j = 0; j<n; j++){
        if(isSafe(board, i, j, n)){
            board[i][j] = 1;
            nQueen(board, i+1, n);
            board[i][j] = 0;
        }
    }
    return;
}

int main(){
    int board[10][10] = {0};
    int n;
    cin>>n;
    nQueen(board,0, n);
}
