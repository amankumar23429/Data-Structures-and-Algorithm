#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n] = {0};
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int pd = arr[1]-arr[0];
    int current = 2;
    int answer = 2;

    for(int i = 2; i<n; i++){
        if ((arr[i]-arr[i-1])==pd){
            current++;
            answer = max(current, answer);
        }else{
            pd = arr[i]-arr[i-1];
            current = 2;
        }
    }

    cout<<answer;

    return 0;
}