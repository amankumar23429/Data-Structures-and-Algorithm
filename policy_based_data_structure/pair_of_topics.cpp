#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

int main(){
    PBDS st;
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int c[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
        c[i] = a[i]-b[i];
    }
    
    long long int inversion_count = 0;
    for(int i = 0; i<n; i++){
        inversion_count += st.size() - st.order_of_key({-c[i], 10000000});
        st.insert({c[i], i});
    }
    cout<<inversion_count<<endl;
    return 0;
}