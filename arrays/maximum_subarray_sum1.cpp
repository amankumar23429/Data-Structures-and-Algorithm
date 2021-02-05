#include<iostream>
using namespace std;


int main(){
    int a[100] = {0};
    int n = 0;
    int sum = 0;
    int left = -1;
    int right = -1;

    cin>>n;

    // takes array input
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int current_sum = 0;
            for(int k = i; k<=j; k++){
                current_sum += a[k];
            }
            if (current_sum>sum){
                sum = current_sum;
                left = i;
                right = j;
            }
            cout<<current_sum<<endl;
        }
    }

    cout<<"maximum sum is "<<sum;
    cout<<"starting index "<<left<<" ending index "<<right<<endl;
    
    return 0;
}