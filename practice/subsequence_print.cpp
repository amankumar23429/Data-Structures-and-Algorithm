#include<bits/stdc++.h>
using namespace std;

int total_sebsequence(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    int smallerOutputSize = total_sebsequence(input.substr(1), output);
    for(int i = 0; i<smallerOutputSize; i++){
        output[smallerOutputSize+i] = input[0] + output[i];  
    }
    return 2*smallerOutputSize;
}

int main(){
    string input;
    cin>>input;
    int n = pow(2,input.size());
    string* output = new string[n];
    int count = total_sebsequence(input, output);
    for(int i = 0; i<count; i++){
        cout<<output[i]<<endl;
    }
}