#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int a[], int n, int students, int max_pages){
    int stud = 1;
    int page_read = 0;
    for(int i = 0; i<n; i++){
        if(page_read+a[i] > max_pages){
            page_read = a[i];
            stud++;
            if(stud>students){
                return false;
            }
        }else{
            page_read += a[i];
        }
    }
    return true;
}

int maximizePages(int a[], int n, int m, int all_pages_sum){
    int s = a[n-1];
    int e = all_pages_sum;
    
    int ans = INT_MAX;

    while(s<=e){
        int mid = (s + e)/2;
            
        if(isPossible(a, n, m, mid)){
            ans = min(mid,ans);
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}



int main(){

    int t,n,m;
    cin>>t;

    for (int j = 0; j<t; j++){
        cin>>n>>m;
        int arr[n];
        int sum = 0;

        if(m>n){
            return -1;
        }
        
        for (int i = 0; i<n; i++){
            int num;
            cin>>num;
            arr[i] = num;
            sum += num;
        }
        cout<<maximizePages(arr,n,m,sum)<<endl;
    }

    return 0;
}