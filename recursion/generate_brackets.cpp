#include<iostream>
using namespace std;

void generating_brackets(char * ch, int n, int idx, int open, int close){
    if(idx==2*n){
        ch[idx] = '\0';
        cout<<ch<<endl;
        return;
    }
    if(open<n){
        ch[idx] = '(';
        generating_brackets(ch, n, idx+1, open+1, close);
    }
    if(close<open){
        ch[idx] = ')';
        generating_brackets(ch, n, idx+1, open, close+1);
    }
}

int main(){
    int n;
    cin>>n;

    char arr[1000];
    generating_brackets(arr, n, 0, 0, 0);
    
    return 0;
}