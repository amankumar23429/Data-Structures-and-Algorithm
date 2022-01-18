#include<bits/stdc++.h>
using namespace std;

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

bool search(node* root, int d){
    if(root==NULL){
        return false;
    }

    if(root->data==d){
        return true;
    }
    else if(d < root->data){
        return search(root->left, d);
    }
    else{
        return search(root->right, d);
    }
}

node* delete_in_BST(node* root, int d){
    if(root==NULL){
        return NULL;
    }

    if(root->data==d){
        // no children
        if(root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 children
        else if(root->left==NULL and root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
         else if(root->left!=NULL and root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        // 2 children
        else{
            node* replace = root->right;
            while(root->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = delete_in_BST(root->right, replace->data);
            return root;
        }

    }
    else if(d < root->data){
        root->left = delete_in_BST(root->left, d);
    }
    else{
        root->right = delete_in_BST(root->right, d);
    }

    return root;
}

void printInorder(node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    node* root = buildBST();
    printInorder(root);
    cout<<"\n"<<search(root, 10)<<endl;
    cout<<search(root, 6)<<endl;
    root = delete_in_BST(root, 6);
    cout<<search(root, 6)<<endl;
    return 0;
}