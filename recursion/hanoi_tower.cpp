#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
// void shift(char src, char dest){

// }

void move(int n, char src, char helper, char dest){
    if(n==0){
        return;
    }
    move(n-1,src,dest,helper);
    cout<<"shift disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    move(n-1, helper, src, dest);
}


int main(){
    move(3,'A','B','C');
    return 0;
}