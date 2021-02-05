#include<iostream>
#include<cstring>
using namespace std;

void remove_dublicates(char c[]){
    int i = 0;
    int j = 1;
    while(j<strlen(c)){
        if (c[i]!=c[j]){
            c[i+1]=c[j];
            i++;
        }
        j++;
    }
    c[i+1] = '\0';
}

void remove_dublicate1(char c[]){
    int i = 0;
    int j = 1;
    for(j;j<strlen(c);j++){
        if(c[i]!=c[j]){
            i++;
            c[i]=c[j];
        }
    }
    c[i+1] = '\0';
}

int main(){
    char c[1000];
    cin>>c;
    remove_dublicate1(c);
    cout<<c;
    
    return 0;
}