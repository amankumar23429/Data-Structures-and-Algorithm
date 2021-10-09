#include<bits/stdc++.h>
using namespace std;

void stockSpan(vector<int> prices, int span[]){
    stack<int> days;
    days.push(0);
    span[0] = 1;

    for(int i = 1; i<prices.size(); i++){
        int curr_price = prices[i];
        while(!days.empty() and curr_price>=prices[days.top()]){
            days.pop();
        }

        if(days.empty()){
            span[i] = i+1;
        }
        else{
            span[i] = i-days.top();
        }
        days.push(i);
    }
}

int main(){
    int n;
    cin>>n;
    int num;
    vector<int> prices;
    for(int i = 0; i<n; i++){
        cin>>num;
        prices.push_back(num);
    }

    int span[n+1];
    memset(span, 0, sizeof(span));

    stockSpan(prices, span);
    for(int i = 0; i<n; i++){
        cout<<span[i]<<" ";
    }

    return 0;
}