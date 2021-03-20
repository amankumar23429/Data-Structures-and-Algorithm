#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int prices[], int n, int span[]){
    stack<int> days;
    days.push(0);

    span[0] = 1;

    for(int i = 1; i<n; i++){
        int currentPrice = prices[i];
        while(!days.empty() and prices[days.top()]<=currentPrice){
            days.pop();
        }

        if(!days.empty()){
            span[i] = i-days.top();
        }
        else{
            span[i] = i+1;
        }
        days.push(i);
    }
}

int main(){
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(int);
    int span[1000] = {0};
    stockSpan(prices, n, span);
    for(int i = 0; i<n; i++){
        cout<<span[i]<<" ";
    }
    return 0;
}

