#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char c[1000];
    char largest[1000];
    int n;
    int len = 0;
    int largest_length = 0;
    cin>>n;
    cin.get();
    for (int i = 0; i<n; i++){
        cin.getline(c,1000);
        len = strlen(c);
        if (len> largest_length){
            largest_length = len;
            strcpy(largest,c);
        }  
    }

    cout<<largest<<endl;
    cout<<largest_length<<endl;

    return 0;
}