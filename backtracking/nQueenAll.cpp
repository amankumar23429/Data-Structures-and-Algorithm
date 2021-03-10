#include<iostream>
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

    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }

    x = i;
    y = j;

    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    return true;
}

bool solveQueen(int board[][10], int i,  int n){
    if(i==n){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    for(int j=0; j<n; j++){
        if(isSafe(board, i, j, n)){
            board[i][j] = 1;
            bool queenRakhPaye = solveQueen(board, i+1, n);
            
            board[i][j] = 0;
        }
    }
    return false;
}

int main(){

    int board[10][10] = {0};
    int n;
    cin>>n;
    solveQueen(board, 0, n);
    
    return 0;
}