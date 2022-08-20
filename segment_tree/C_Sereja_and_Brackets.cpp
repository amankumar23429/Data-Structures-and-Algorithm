#include <iostream>
using namespace std;
#define ll long long int
typedef pair<int, int> PII;
typedef pair<int,PII> node;

const int maxi =  1e6*4+5;
int open[maxi], close[maxi], full[maxi];
string s;
 
void build(int idx, int low, int high){
    if(low==high){
        open[idx] = (s[low]=='(');
        close[idx] = (s[low]==')');
        full[idx] = 0;
        return;
    }
 
    int mid = (low+high)/2;
    build(2*idx+1, low, mid);
    build(2*idx+2, mid+1, high);
    int s1 = 2*idx+1;
    int s2 = 2*idx+2;
    int temp = min(open[s1], close[s2]);
    full[idx] = full[s1] + full[s2] + temp;
    open[idx] = open[s1] + open[s2] - temp;
    close[idx] = close[s1] + close[s2] - temp;
}
 
node query(int idx, int low, int high, int l, int r){
    if(high<l or r<low){
        return {0, {0, 0}} ;
    }
    if(low>=l && high<=r){
        return {open[idx], {close[idx], full[idx]}};
    }
    int mid = (low+high)/2;
    node left = query(2*idx+1, low, mid, l, r);
    node right =  query(2*idx+2, mid+1, high, l, r);
    node ans;
    int temp = min(left.first, right.second.first);
    ans.first = left.first+right.first - temp;
    ans.second.first = left.second.first + right.second.first - temp;
    ans.second.second = left.second.second + right.second.second + temp;
    return ans;
}
 
int main (){
    cin>>s;
    int q;
    cin>>q;
    int n = s.size();
    build(0, 0, n-1);
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(0, 0, n-1, l, r).second.second*2<<endl;
    }
    return 0;
}