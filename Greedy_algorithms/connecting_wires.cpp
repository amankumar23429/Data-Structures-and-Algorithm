#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int white_dots[n];
    int black_dots[n];
    for(int i = 0; i<n; i++){
        cin>>white_dots[i];
    }
    for(int i = 0; i<n; i++){
        cin>>black_dots[i];
    }

    sort(white_dots, white_dots+n);
    sort(black_dots, black_dots+n);

    int ans = 0;
    for(int i = 0; i<n; i++){
        ans += abs(white_dots[i]-black_dots[i]);
    }
    cout<<ans<<endl;
    return 0;
}