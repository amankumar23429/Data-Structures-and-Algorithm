#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    node(){
        left = NULL;
        right =NULL;
    }
};

class Trie{
    node* root;
    public:
    Trie(){
        root = new node();
    }

    void insert(int n){
        node* temp = root;
        for(int i = 31; i>=0; i--){
            int bit = (n>>i)&1;
            if(bit==0){
                // if bit is 0
                if(temp->left==NULL){
                    temp->left = new node();
                }
                temp = temp->left;
            }else{
                // if bit is 1
                if(temp->right==NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int value){
        node* temp = root;
        int current_ans = 0;
        for(int i = 31; i>=0; i--){
            int bit = (value>>i)&1;
            if(bit==0){
                if(temp->right!=NULL){
                    temp = temp->right;
                    current_ans += (1<<i);
                }else{
                    temp = temp->left;
                }
                
            }else{
                // if bit is 1
                if(temp->left!=NULL){
                    temp = temp->left;
                    current_ans += (1<<i);
                }
                else{
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    int output(int *arr, int n){
        int max_xor = 0;
        for(int i = 0; i<n; i++){
            int val = arr[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            //cout<<current_xor;
            max_xor = max(max_xor, current_xor);
        }
        return max_xor;
    }
};

int main(){
    int input[] = {3,10,5,25,2,8};
    int commulative_xor[6] = {0};
    int n = sizeof(input)/sizeof(int);
    int current_xor = input[0];
    commulative_xor[0] = current_xor;
    for(int i = 1; i<n; i++){
        current_xor = commulative_xor[i-1]^input[i];
        commulative_xor[i] = current_xor;
    }
    Trie t;
    cout<<t.output(commulative_xor, n);
    return 0;
}