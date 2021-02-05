#include<iostream>
using namespace std;

int main(){
    int a[100][100] = {0};
    int sum_mat[100][100] = {0};
    int m,n;
    cin>>m>>n;
    int value = 1;

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = value;
            value++;
        }
    }

    // column wise sum

    for (int i = 0; i<m; i++){
        for(int j = 1; j<n; j++){
            a[i][j] += a[i][j-1];
        }
    }

    // row wise sum
    for (int i = 0; i<n; i++){
        for(int j = 1; j<m; j++){
            a[j][i] += a[j-1][i];
        }
    }

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            for(int k = i; k<m; k++){
                for(int l = j; l<n; l++){
                    if(i==0 && j==0){
                        cout<<a[k][l]<<" ";

                    }else if (i==0 && j>0){
                        cout<<a[k][l]-a[k][l-1]<<" ";
                    }
                    else if(j==0 && i>0){
                        cout<<a[k][l]-a[k-1][l]<<" ";
                    }
                    else{
                        if(i>0 && j>0){
                            int sum = a[k][l] - a[k][j-1] - a[i-1][l] + a[i-1][j-1];
                            cout<<sum<<" ";
                        }
                    }
                    
                    
                }
            }     
        }
    }

    
    return 0;
}