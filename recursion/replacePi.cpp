#include<iostream>
#include<cstring>
using namespace std;

void replacePi(char ch[], int i){
    
    if(ch[i]=='\0'){
        return;
    }
    
    if(ch[i]=='p' and ch[i+1] == 'i'){
        int j = i+2;
        while(ch[j]!='\0'){
            j++;
        }
        while(j>=i+2){
            ch[j+2] = ch[j];
            j--;
        }
        ch[i]   = '3';
        ch[i+1] = '.';
        ch[i+2] = '1';
        ch[i+3] = '4';
        replacePi(ch,i+4);

    }else{
        replacePi(ch, i+1);
    }

    return;
}

int main(){
    
    char c[1000] = "p";
    replacePi(c,0);

    cout<<c;
    
    return 0;
}