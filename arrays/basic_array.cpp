#include<iostream>
using namespace std;
int main(){
    int a[10] = {2,4,6};
    for (int i = 0; i<5; i++){
        cin>>a[i];
    }
    

    for (int j = 0 ; j<10; j++){
        cout<<a[j]<<" ,";
    }
    cout<<sizeof(a)<<endl;
    return 0;
}