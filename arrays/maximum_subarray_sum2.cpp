#include<iostream>
using namespace std;


int main(){
    int a[100] = {0};
    int cummulative_sum[100] = {0};
    int n = 0;
    int max_sum = 0;
    int current_sum = 0;
    int left = -1;
    int right = -1;

    cin>>n;

    // to avoid general mistake important step
    cin>>a[0];
    cummulative_sum[0] = a[0];
    
    for(int i=1; i<n; i++){
        cin>>a[i];
        cummulative_sum[i] = a[i] + cummulative_sum[i-1];
    }

    
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if (i>0){
                current_sum = cummulative_sum[j]-cummulative_sum[i-1];
            }
            else{
                current_sum = cummulative_sum[j];
            }
            if (current_sum > max_sum){
                max_sum = current_sum;
                left = i;
                right = j;
            }
        }
       
    }
    cout<<max_sum<<endl;
    cout<<"starting index "<<left<<" ending index "<<right<<endl;
    
    return 0;
}