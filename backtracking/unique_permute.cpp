#include<iostream>
#include<set>
#include<string>
using namespace std;

void permute(char * in, int i, set<string> &s){
    if(in[i]=='\0'){
        string t(in);
        s.insert(t);
        return;
    }

    for(int j = i; in[j]!='\0'; j++){
        swap(in[i], in[j]);
        permute(in, i+1, s);
        swap(in[i], in[j]);
    }
}

int main(){
    char ch[100];
    cin>>ch;
    set<string> s;
    permute(ch, 0, s);

    for(auto x:s){
        cout<<x<<" ";
    }
    
    return 0;
}