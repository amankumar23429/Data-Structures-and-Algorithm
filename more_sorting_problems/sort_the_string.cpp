#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int str_to_int(string s){
    int ans = 0;
    for(int i = 0; i<s.length(); i++){
        ans = ans * 10 + (s[i]-'0');
    }
    return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2){
    int num1 = str_to_int(s1.second);
    int num2 = str_to_int(s2.second);
    return num1<num2;
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2){
    return s1.second < s2.second;
}

string extract_string_token(string str, int key){
    char *token = strtok((char*)str.c_str(), " ");
    int i = 1;
    while(i<key){
        token = strtok(NULL, " ");
        i++;
    }
    return string(token);
}

int main(){
    int n;
    cin>>n;
    cin.get();
    string str[n];

    for(int i = 0; i<n; i++){
        getline(cin, str[i]);
    }

    int key;
    string reverse, ordering;
    cin>>key>>reverse>>ordering;
    
    pair<string, string> strPair[n];
    for(int i = 0; i<n; i++){
        strPair[i].first = str[i];
        strPair[i].second = extract_string_token(str[i], key);
    }
    
    if(ordering=="numeric"){
        sort(strPair, strPair+n, numericCompare);
    }else{
        sort(strPair, strPair+n, lexicoCompare);
    }
    if(reverse=="true"){
        for(int i = 0; i<n/2; i++){
            swap(strPair[i], strPair[n-i-1]);
        }
    }

    for(int i = 0; i<n; i++){
        cout<<strPair[i].first<<endl;
    }
    
    return 0;
}