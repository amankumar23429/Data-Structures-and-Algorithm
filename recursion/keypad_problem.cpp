#include<iostream>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generating_names(char * in, char * out, int i, int j){
    
    if(in[i]=='\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    int digit = in[i] - '0';
    if(digit==0 || digit==1){
        generating_names(in, out, i+1, j+1);
    }

    for(int k = 0; keypad[digit][k]!='\0'; k++){
        out[j] = keypad[digit][k];

        generating_names(in, out, i+1, j+1);
    }
}

int main(){
    char in[100];
    cin>>in;
    
    char out[100];
    generating_names(in, out, 0, 0);
    
    return 0;
}