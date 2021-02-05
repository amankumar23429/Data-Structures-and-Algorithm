#include<iostream>
using namespace std;

void readline(char c[], int maxlen, char delimiter = '\n'){
    int i = 0;
    char ch;
    ch = cin.get();
    
    while(ch != delimiter){
        c[i] = ch;
        i++;
        if(i == maxlen-1){
            break;
        }
        ch = cin.get();
    }
    c[i] = '\0';
}

int main(){
    char c[1000];
    char d[1000];
    readline(c, 1000);
    // another method by using inbuilt function
    cin.getline(d,1000);
    cout<<c<<endl;
    cout<<d<<endl;

    return 0;
}