#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    unordered_map<char, Node*> children;
    int count;
    
    Node(char d){
        data = d;
        count = 0;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node('\0');
    }

    void insert(char *w){
        Node* temp = root;
        for(int i = 0; w[i]!='\0'; i++){
            char ch = w[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
                temp->count++;
            }
            else{
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
                temp->count++;
            }
            
        }
    }

    void output(char *w){
        Node* temp = root;
         for(int i = 0; w[i]!='\0'; i++){
            char ch = w[i];
            if(temp->children[ch]->count==1){
                for(int j = 0; j<=i; j++){
                    cout<<w[j];
                }
                cout<<endl;
                return ;
            }
            else{
                temp = temp->children[ch];
            }
        }
        cout<<-1<<endl;
        return ;
    }
};

int main(){
    Trie t;
    char words[][10] = {"cobra","dog", "dove", "duck"};
    for(int i = 0; i<4;i++){ 
        t.insert(words[i]);
    }
    
    for(int i = 0; i<4; i++){
        t.output(words[i]);
    }
    return 0;
}