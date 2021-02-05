#include<iostream>
using namespace std;

int clearItoJbits(int n, int i, int j){
    int a = -1<<(j+1);
    int b = (1<<i) - 1;

    int mask = a | b;
    return mask & n;

}

int replaceBits(int n, int m, int i, int j){
    int clearBit = clearItoJbits(n,i,j);
    m = m<<i;
    return m | clearBit;
}


int main(){
    
    int n,m,i,j;
    cin>>n>>m>>i>>j;
    cout<<replaceBits(n, m, i, j)<<endl;

    return 0;
}