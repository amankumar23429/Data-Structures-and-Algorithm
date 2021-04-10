#include<iostream>
#include<queue>
using namespace std;


int main(){
    queue<char> q;
    int freq[27] = {0};

    char ch;
    cin>>ch;

    while(ch!='.'){
        q.push(ch);
        int ind = ch - 'a';
        freq[ind]++;
        
        while(!q.empty()){
            if(freq[q.front()-'a']>1){
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty()){
            cout<<"-1"<<endl;
        }
        
        cin>>ch;
    }
    
    return 0;
}