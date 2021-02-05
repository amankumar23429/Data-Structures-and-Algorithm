#include<iostream>
using namespace std;

void rotate(int a[][100], int n){

    for (int i = 0; i<n; i++){
        int last = n-1;
        for(int j = 0; j<last; j++){
            swap(a[i][j], a[i][last]);
            last--;
        }
    }

    for (int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            swap(a[i][j], a[j][i]);
        }
    }
}

void display(int a[][100], int n){
    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int a[100][100];
    int n;
    cin>>n;

    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }

    rotate(a, n);
    display(a, n);

    return 0;
}