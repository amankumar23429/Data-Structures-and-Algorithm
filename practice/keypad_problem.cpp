#include<bits/stdc++.h>
using namespace std;

int keypad_sequence(string input, string output[], string keypad[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    int smallerOutputSize = keypad_sequence(input.substr(1), output, keypad);
    int number = input[0]-'0';
    string s = keypad[number];
    string s1[smallerOutputSize];
    for(int i = 0; i<smallerOutputSize; i++){
        s1[i] = output[i];
    }

    for(int i = 0; i<s.size(); i++){
        for(int j = 0; j<smallerOutputSize; j++){
            int temp = (i*smallerOutputSize)+j;
            output[temp] = s[i] + s1[j];
        }
    }
    
    return (s.size())*smallerOutputSize;
}

int main(){
    string input;
    cin>>input;
    string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    string* output = new string[1000];
    int count = keypad_sequence(input, output, keypad);
    for(int i = 0; i<count; i++){
        cout<<output[i]<<endl;
    }
}
