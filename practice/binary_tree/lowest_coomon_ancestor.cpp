#include <bits/stdc++.h>
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

void levelOrderBuild(node* &root){
    int d;
    queue<node*> q;
    cin>>d;
    if(d!=-1){
        root = new node(d);
        q.push(root);
    }
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            temp->left = new node(c1);
            q.push(temp->left);
        }

        if(c2!=-1){
            temp->right = new node(c2);
            q.push(temp->right);
        }
    }
}

node* lca(node* root, int a, int b){
    if(root==NULL){
        return NULL;
    }

    if(root->data == a or root->data == b){
        return root;
    }

    node* leftAns = lca(root->left, a, b);
    node* rightAns = lca(root->right, a, b);

    if(leftAns!=NULL and rightAns!=NULL){
        return root;
    }

    if(leftAns!=NULL){
        return leftAns;
    }

    return rightAns;
}

int main (){
    node* root = NULL;
    levelOrderBuild(root);
    //bfs(root);
    cout<<lca(root, 10, 4)->data;
    return 0;
}