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
        int last = n-1;
        for(int j = 0; j<last; j++){
            swap(a[i][j], a[i][last]);
            last--;
        }
    }

    for (int i = 0; i<m; i++){
        for(int j = 0; j<i; j++){
            swap(a[i][j], a[j][i]);
        }
    }

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}