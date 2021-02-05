#include<iostream>
#include<cstring>
using namespace std;

char *new_strtok(char *str, char delim){
    static char *input = NULL;
    if (str != NULL){
        input = str;
    }
    if(input ==NULL){
        return NULL;
    }
    int i = 0;
    char *output = new char[strlen(input)+1];
    for(i ; input[i] != '\0'; i++){
        if(input[i] != delim){
            output[i] = input[i];
        }
        else{
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    output[i] = '\0';
    input = NULL;
    return output;
}


int main(){
    
    char c[100]  = "today is not a rainy day, I wake early, in the morning";

    char *sptr = new_strtok(c, ',');

    cout<<sptr<<endl;

    while(sptr != NULL){
        sptr = new_strtok(NULL, ',');
        cout<<sptr<<endl;
    }


    return 0;
}