#include<iostream>
using namespace std;

void selection_sort(int a[], int n){

    for(int i = 0; i < n-1; i++){

        int min_index = i;

        for (int j = i; j<=n-1; j++){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }

}

int main(){
    
    int n,i = 0;
    int a[100];
    cout << "enter the total elements in an array";
    cin >> n;

    cout << "enter the elements of an array";
    for (int j = 0; j<n; j++){
        cin>>a[j];
    }
    
    selection_sort(a, n);

    for(int i = 0; i<n; i++){
        cout << a[i] << ";";
    }
    return 0;
}
