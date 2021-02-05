#include<iostream>
using namespace std;

int main(){
    int a[100][100]={0};
    int m,n;
    cin>>m>>n;
    int value = 1;

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = value;
            value++;
        }
    }

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            for(int k = i; k<m; k++){
                for(int l = j; l<n; l++){
                    int sum = 0;
                    for(int x = i; x<=k; x++){
                        for(int y = j; y<=l; y++){
                            sum += a[x][y];
                        }
                    }
                    cout<<sum<<" ";
                }
            }     
        }
    }

    
    return 0;
}