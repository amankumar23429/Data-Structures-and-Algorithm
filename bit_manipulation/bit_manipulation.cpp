#include<iostream>
using namespace std;

int isOdd(int n){
    return n&1;
}

int getBit(int n,int pos){
    int mask = 1<<pos;
    return (n & mask != 0);
}

int setBit(int n, int pos){
    int mask = 1<<pos;
    return (n | mask);
}

void clearBit(int &n, int pos){
    int mask = ~(1<<pos);
    n = mask & n;
}

void updateBit(int &n, int pos, int val){
    int mask = ~(1<<pos);
    int temp_n = n & mask;
    n = temp_n | (val<<pos);
}

int clearLastIbits(int n, int i){
    int mask = -1<<i;
    return mask & n;
}

int clearItoJbits(int n, int i, int j){
    int a = -1<<(j+1);
    int b = (1<<i) - 1;

    int mask = a | b;
    return mask & n;

}

int main(){
    // int n, p;
    // cin>>n>>p;
    // int n = 5;
    // int  m = 7;
    
    // cout<<getBit(5, 2)<<endl;
    // cout<<setBit(5, 1)<<endl;
    // clearBit(n, 2);
    // cout<<n<<endl;
    
    // updateBit(m,1,0);

    // cout<<m<<endl;
    cout<<clearLastIbits(15,3)<<endl;

    cout<<clearItoJbits(31,1,3)<<endl;


    return 0;
}