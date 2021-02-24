#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

void generating_strings(char *input, char *out, int i, int j){
    if(input[i]=='\0'){
        out[j] = '\0';
        cout<<out<<"\n";
        return;
    }
    int digit = input[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    //take single digit  at a time
    generating_strings(input, out, i+1, j+1);
    // take two digits at a time
    if(input[i+1]!='\0'){
        int next_digit = input[i+1] - '0';
        int no = digit*10 + next_digit;
        if(no<=26){
            char ch2 = no + 'A' - 1;
            out[j] = ch2;
            generating_strings(input, out, i+2, j+1);
        }
    }
}

int main(){
    char input[] = "1234";
    char out[10];
    generating_strings(input, out, 0, 0);
    return 0;
}