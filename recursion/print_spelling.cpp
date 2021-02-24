#include<iostream>
#include<algorithm>
using namespace std;

void printSpelling(int n){
    char words[][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(n==0){
        return;
    }
    printSpelling(n/10);
    int digit = n%10;
    cout<<words[digit]<<" ";
}

int main(){
    int n;
    cin>>n;
    printSpelling(n);
    
    return 0;
}