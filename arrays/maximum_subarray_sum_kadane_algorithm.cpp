#include<iostream>
using namespace std;


int main(){
    int a[100] = {0};
    int n = 0;
    int max_sum = 0;
    int current_sum = 0;
    
    cin>>n;

    // takes array input
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i = 0; i<n; i++){
        current_sum += a[i];
        if (current_sum < 0){
            current_sum = 0;
        }
        if(current_sum > max_sum){
            max_sum = current_sum;
        }
    }

    cout<<"maximum sum is "<<max_sum;
    
    return 0;
}