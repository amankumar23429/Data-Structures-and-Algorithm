#include<iostream>
#include<cstring>
using namespace std;

void filterChar(char c[], int n){
    int j = 0;
    while(n>0){
        if(n&1){
            cout<<c[j];
        }
        n = n>>1;
        j++;
    }
}

void printSubsets(char c[]){
    int n = strlen(c);
    for(int i = 0; i<(1<<n); i++){
        filterChar(c,i);
        cout<<endl;
    }
}

int main(){
    char ch[100];
    cin>>ch;

    int n = strlen(ch);
    printSubsets(ch);
    
    return 0;
}