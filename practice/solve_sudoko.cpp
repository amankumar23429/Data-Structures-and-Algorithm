#include<bits/stdc++.h>
using namespace std;
#define n 9

bool isPlace(int grid[][9], int i, int j, int num){
    for(int x = 0; x<n; x++){
        if(grid[i][x]==num or grid[x][j]==num){
            return false;
        }
    }
    int sr = sqrt(n);
    int sx = (i/sr)*sr;
    int sy = (j/sr)*sr;

    for(int x = sx; x < sx+sr; x++){
        for(int y = sy; y < sy+sr; y++){
            if(grid[x][y]==num){
                return false;
            }
        }
    }
}
bool solveSudoko(int grid[][9], int i, int j){
    if(i==n){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                cout<<grid[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j>=n){
        return solveSudoko(grid, i+1, 0);
    }
    if(grid[i][j]!=0){
        return solveSudoko(grid, i, j+1);
    }

    for(int x = 1; x<=n; x++){
        if(isPlace(grid, i, j, x)){
            grid[i][j] = x;
            bool couldWeSolve = solveSudoko(grid, i, j+1);
            if(couldWeSolve){
                return true;
            }
        }
    }
    grid[i][j] = 0;
    return false;
}

int main(){
    int grid[n][n];
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cin>>grid[x][y];
        }
    }

    solveSudoko(grid, 0, 0);
    return 0;
}