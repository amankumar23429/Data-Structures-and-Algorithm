#include<bits/stdc++.h>
using namespace std;

bool balancedParenthesis(string s){
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            if(st.empty() or st.top()!='('){
                return false;
            }
            else st.pop();
        }
    }

    return st.empty();
}

int main(){
    string s;
    cin>>s;
    cout<<balancedParenthesis(s);
    return 0;
}