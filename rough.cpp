#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <int> v = {1,23,4};
	vector<pair<int, int>> v2;
	v2.push_back(make_pair(1,0));
	v2.push_back(make_pair(23,1));
	v2.push_back(make_pair(4,2));
	sort(v2.begin(), v2.end());
	for(auto x:v2){
		cout<<x.first<<" "<<x.second<<endl;
	}
    return 0;
}