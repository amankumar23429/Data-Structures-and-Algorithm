#include<iostream>
using namespace std;

bool compare(int a, int b){
    return a<b;
}

void bubble_sort(int a[], int n, bool (&comp)(int a , int b)) {
    for(int i = 0; i<n-1; i++ ){
        for(int j = 0; j<n-1-i; j++){
            if (comp(a[j], a[j+1])){
                swap(a[j],a[j+1]);
            }
        }
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
    
    bubble_sort(a, n, compare);

    for(int i = 0; i<n; i++){
        cout << a[i] << ";";
    }
    return 0;
}