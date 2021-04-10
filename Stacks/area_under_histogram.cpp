#include<iostream>
#include<stack>
using namespace std;

int max_area(int bar[], int n){
    stack<int> s;
    s.push(0);

    int max_area = 0;
    int area = 0;
    int i;

    for(i = 1; i<n; i++){  
        if(bar[i] >= bar[s.top()]){
            s.push(i);
        }
        else{
            while(!s.empty() and bar[i] < bar[s.top()]){
                int top = s.top();
                s.pop();
                if(s.empty()){
                    area = bar[top]*i;
                }
                else{
                    area = bar[top] * (i-s.top()-1);
                }
                max_area = max(area, max_area);
            }
            s.push(i);
        }
        
    }

    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(s.empty()){
            area = bar[top]*i;
        }
        else{
            area = bar[top] * (i-s.top()-1);
        }
        max_area = max(area, max_area);
    }

    return max_area;
}

int main(){
    int bar[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(bar)/sizeof(int);
    cout<<max_area(bar, n);
    
    return 0;
}

