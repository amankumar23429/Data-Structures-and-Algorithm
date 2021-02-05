#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string extract_string_key(string str, int key){
    char *ch = strtok((char*)str.c_str()," ");

    while(key>1){
        ch = strtok(NULL," ");
        key--;
    }
    return ch;
}

int str_to_num(string s){
    int ans = 0;
    int p = 1;
    int len = s.length()-1;
    while (len>=0){
        ans += (s[len]-'0')*p;
        p = p*10;
        len--;
    }
    return ans;

}

bool numeric_compare(pair<string, string> a, pair<string, string> b){
    return str_to_num(a.second) < str_to_num(b.second);
}

bool lexico_compare(pair<string, string> a, pair<string, string> b){
    return a.second < b.second;
}


int main(){
    string s[100];
    int n;
    cin>>n;
    cin.get();

    for(int i = 0; i < n; i++){
        getline(cin,s[i]);
    }

    int key;
    string ordering;
    string reverse;

    cin>>key;
    cin>>reverse>>ordering;

    pair<string,string> strPair[n];

    for(int i = 0; i < n; i++){
        strPair[i].first = s[i];
        strPair[i].second = extract_string_key(s[i],key);
    }

    if(ordering=="numeric"){
        sort(strPair, strPair+n, numeric_compare);
    }
    else{
        sort(strPair, strPair+n, lexico_compare);
    }

    if(reverse == "true"){
        int i = 0;
        for (int i = 0; i<n/2; i++){
            swap(strPair[i],strPair[n-i-1]);
        }
    }

    for(int i = 0; i < n; i++){
        cout<<strPair[i].first<<endl;
    }
    
    return 0;
}