#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char *ch, int n){
    char words[] = {'0','1','2','3','4','5','6','7','8','9'};
    if(n==0){
        return 0;
    }
    
    int digit = ch[n-1]-'0';
    int smaller_ans = stringToInt(ch, n-1);

    return smaller_ans*10+digit;
}

int main(){
    
    char c[] = "52542";
    int n = strlen(c);
    cout<<stringToInt(c,n);
    
    return 0;
}