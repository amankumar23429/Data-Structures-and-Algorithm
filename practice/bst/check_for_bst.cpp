#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* insertion(node* root, int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }

    if(data <= root->data){
        root->left = insertion(root->left, data);
    }
    else{
        root->right = insertion(root->right, data);
    }
    return root;
}

node* buildBST(){
    int d;
    cin>>d;
    node*root = NULL;
    while(d!=-1){
        root = insertion(root, d);
        cin>>d;
    }
    return root;
}

bool isBST(node* root, int l = INT_MIN, int r = INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data>=l and root->data<=r){
        if(isBST(root->left, l, root->data) and isBST(root->right, root->data, r)){
            return true;
        }
    }
    return false;
}

int main (){
    node*root = buildBST();
    cout<<isBST(root);
    return 0;
}