#include<bits/stdc++.h>
using namespace std;

void print_keypad_sequence(int input, string output, string keypad[]){
    if(input==0){
        cout<<output<<endl;
        return;
    }
    int num = input%10;
    for(int i = 0; i<keypad[num].size(); i++){
        print_keypad_sequence(input/10, keypad[num][i] + output, keypad);
    }
    return;
}

int main(){
    int input;
    cin>>input;
    string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    string output = "";
    print_keypad_sequence(input, output, keypad);
}
