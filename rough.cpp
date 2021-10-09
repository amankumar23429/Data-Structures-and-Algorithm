#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

class Solution {
public:
    set<string> ans;
	
    void count_sub(string s, int i, int j, char* out){
        if(i==s.size()){
            out[j] = '\0';
			string as = out;
            ans.insert(as);
            return;
        }
        out[j] = s[i];
        count_sub(s, i+1, j+1, out);
        count_sub(s, i+1, j, out);
		return;
    }
    
    int distinctSubseqII(string s) {
		char output[2000];
		count_sub(s, 0, 0, output);
		// for(auto p:ans)
		// cout<<p<<endl;
		// cout<<ans.size()<<endl;
		return ans.size()-1;
    }
};

int main(){
    string s;
	cin>>s;

	Solution as;
	cout<<as.distinctSubseqII(s);

    return 0;
}
