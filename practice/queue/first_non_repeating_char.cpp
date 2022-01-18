#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<char> q;
    char ch;
    cin>>ch;
    int freq[27] = {0};
    while(ch!='.'){
        q.push(ch);
        freq[ch-'a']++;

        while(!q.empty()){
            if(freq[q.front()-'a'] > 1){
                q.pop();
            }
            else{
                break;
            }
        }
        cin>>ch;
    }
    cout<<q.front()<<endl;
    return 0;
}