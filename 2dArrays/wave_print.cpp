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
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int j = 0;j<n; j++){
        if(j%2==0){
            for (int i = 0; i<m; i++){
                cout<<a[i][j]<<" ";
            }
        }else{
            for (int i = m-1; i>=0; i--){
                cout<<a[i][j]<<" ";
            }
        }
    }
    return 0;
}