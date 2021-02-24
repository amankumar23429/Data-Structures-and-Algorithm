#include<iostream>
#include<algorithm>
using namespace std;

bool canPlaceCows(int a[], int n, int cows, int min_cows){
    int last_cow = a[0];
    int count  = 1;
    for (int i = 1; i<n; i++){
        if ((a[i] - last_cow) >= min_cows){
            last_cow = a[i];
            count++;
        }
        if(count==cows){
            return true;
        }
    }
    return false;
}



int main(){

    int t,n,c;
    cin>>t;

    for (int j = 0; j<t; j++){
        cin>>n>>c;
        int arr[n];
        for (int i = 0; i<n; i++){
            cin>>arr[i];
        }

        sort(arr, arr+n);

        int s = 0;
        int e = arr[n-1] - arr[0];
        int ans = 0;


        while(s<=e){
            int mid = (s + e)/2;
            
            if(canPlaceCows(arr,n,c,mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;

}