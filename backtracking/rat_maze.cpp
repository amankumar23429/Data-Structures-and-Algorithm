#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

bool ratInMaze(char maze[10][10], int out[][10], int i, int j, int m, int n){
    if(i==m && j==n){
        out[m][n] = 1;
        for(int i = 0; i<=m; i++){
            for(int j = 0; j<=n; j++){
                cout<<out[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl; 
        return true;
    }
    if(i>m || j>n){
        return false;
    }
    if(maze[i][j] =='X'){
        return false;
    }
    out[i][j] = 1;
    bool right_success = ratInMaze(maze, out, i, j+1, m, n);
    bool down_success = ratInMaze(maze, out, i+1, j, m, n);

    out[i][j] = 0; // backtracking

    if(right_success ||  down_success){
        return true;
    }
    return false;
};


int main(){
    char maze[10][10] = {"0000", "00X0", "000X", "0X00"};
    int out[10][10] = {0};
    int m = 4;
    int n = 4;

    ratInMaze(maze, out, 0, 0, m-1, n-1);
    
    return 0;
}