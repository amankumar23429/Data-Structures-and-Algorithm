#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int max_area(int bar[], int n){
    stack<int> s;
    s.push(0);

    vector<int> area;

    for(int i = 1; i<n; i++){
        
        if(bar[i] >= bar[s.top()]){
            s.push(i);
        }
        else{
            while(!s.empty() and bar[i] < bar[s.top()]){
                int top = s.top();
                s.pop();
                if(s.empty()){
                    int a = bar[top]*i;
                    area.push_back(a);
                }
                else{
                    int a = bar[top] * (i-s.top()-1);
                    area.push_back(a);
                }
            }
            s.push(i);
        }        
    }
    int arr = 0;
    for(auto x:area){
        arr = max(arr, x);
    }
    return arr;
}

int main(){
    int bar[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(bar)/sizeof(int);
    cout<<max_area(bar, n);
    
    return 0;
}

