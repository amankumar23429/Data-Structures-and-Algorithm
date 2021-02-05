#include<iostream>
#include<cstring>
using namespace std;


int main(){
    
    char c[100]  = "today is not a rainy day, I wake early in the morning";

    char *sptr = strtok(c, ",");

    
    cout<<sptr<<endl;

    while(sptr != NULL){
        sptr = strtok(NULL, ",");
        cout<<sptr<<endl;
    }


    return 0;
}