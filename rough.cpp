#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define ll long long
using namespace std;

int main(){
    int c;
    cin>>c;
    int n = 1;
    while((n*(n+1))/2<c){
        n++;
    }
    cout<<n<<endl;
    return 0;
}

// int main(){
//     ll t;
//     cin>>t;
    
//     for(int i = 0; i<t; i++){
//         ll n, k;
//         cin>>n>>k;
//         ll arr[n];
        
//         for(int j = 0; j<n; j++){
//             cin>>arr[j];
//         }
        
//         sort(arr,arr+n, greater<>());
//         ll prev = INT_MIN;
//         ll ans = 0;
//         ll j = 0;
//         ll max_element = arr[0];
//         while((arr[j]>0 and j<n and k>0) or prev==arr[j]){
//             ans+=arr[j];
//             if(prev!=arr[j]){
//                 k--;
//             }
//             prev = arr[j];
//             j++;
//         }
//         if(ans==0){
//             cout<<max_element<<endl;
//         }
//         else{
//             cout<<ans<<endl;
//         }
//     }
//     return 0;
// }