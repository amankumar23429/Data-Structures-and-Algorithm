#include<iostream>
using namespace std;

#define R 8
#define C 8
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void printMat(int mat[][C]){
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}

void flood_fill(int mat[][C], int i, int j, int prevChar, int newChar){
    if(i<0 or j<0 or i>=R or j>=C){
        return;
    }

    if(mat[i][j]!= prevChar){
        return;
    }
    if(mat[i][j]==newChar){
        return;
    }
    mat[i][j] = newChar;
    for(int k = 0; k<4; k++){
        flood_fill(mat, i+dx[k], j+dy[k], prevChar, newChar);
    }
}



int main(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

    int screen[R][C] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1}
                     };
    // cin>>R>>C;
    // char mat[R][30];
    // for(int i = 0; i<R; i++){
    //     for(int j = 0; j<C; j++){
    //         cin>>mat[i][j];
    //     }
    // }
    flood_fill(screen, 4, 4 ,2, 3);
    printMat(screen);
    return 0;
}