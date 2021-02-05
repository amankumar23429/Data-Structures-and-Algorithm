#include<iostream>
#include<cstring>
using namespace std;

bool is_palindrome(char c[]){
    int i = 0;
    int j = strlen(c)-1;
    while(i<j){
        if (c[i]==c[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    char c[1000];
    cin>>c;
    cout<<is_palindrome(c);
    
    return 0;
}