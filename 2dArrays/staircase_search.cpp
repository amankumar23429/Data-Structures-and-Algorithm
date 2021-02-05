#include<iostream>
using namespace std;

void staircase_search(int a[][100], int m, int n, int key){
    int i = 0;
    int j = n-1;

    while(i < m and j >= 0)
    if (key>a[i][j]){
        i++;
    }else if (key<a[i][j]){
        j--;
    }else{
        cout<<"element found at "<<i<<" and "<<j<<" position";
        break;
    }
}

int main(){
    int a[100][100]={0};
    int m, n, key;
    cin>>m>>n;
    cin>>key;
    int value = 1;
    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = value;
            value++;
        }
    }
    staircase_search(a, m, n, key);
}