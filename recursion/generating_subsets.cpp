#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

void generating_subsequence(char *input, char *out, int i, int j){
    if(input[i]=='\0'){
        out[j] = '\0';
        cout<<out<<"\n";
        return;
    }
    out[j] = input[i];
    //include the current character
    generating_subsequence(input, out, i+1, j+1);
    // exclude current character
    generating_subsequence(input, out, i+1, j);

}

int main(){
    char input[] = "abc";
    char out[10];
    generating_subsequence(input, out, 0, 0);
    return 0;
}