#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* insertion_in_BST(node* root, int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }

    if(data<=root->data){
        root->left = insertion_in_BST(root->left, data);
    }
    else{
        root->right = insertion_in_BST(root->right, data);
    }
    return root;
}

node* build_BST(){
    int data;
    cin>>data;
    node *root = NULL;

    while(data!=-1){
        root = insertion_in_BST(root, data);
        cin>>data;
    }
    return root;
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* r = q.front();
        if(r==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<r->data<<" ";
            q.pop();

            if(r->left){
                q.push(r->left);
            }
            if(r->right){
                q.push(r->right);
            }
        }
    }
    return;
}

void printInorder(node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

node* delete_in_BST(node*root, int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = delete_in_BST(root->left, data);
        return root;
    }
    else if(root->data==data){
        // 1). no children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 2). only one children
        if(root->left!=NULL && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        // 3).Two children
        node* replace = root->right;
        // finding inorder successor from right subtree
        while(replace->left!=NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = delete_in_BST(root->right, replace->data);
        return root;
    }
    else{
        root->right = delete_in_BST(root->right, data);
        return root;
    }
}

int main(){
    node *root = build_BST();
    bfs(root);
    cout<<endl;
    int key;
    cin>>key;
    root = delete_in_BST(root, key);
    bfs(root);
    return 0;
}