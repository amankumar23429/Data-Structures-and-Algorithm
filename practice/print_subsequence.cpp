#include<bits/stdc++.h>
using namespace std;

void print_subs(string input, string output){
    if(input.empty()){
        cout<<output<<endl;
        return ;
    }

    print_subs(input.substr(1), output);
    print_subs(input.substr(1), output+input[0]);
    return;
}
int main(){
    string input = "abc";
    string output = "";
    print_subs(input, output);
    return 0;
}