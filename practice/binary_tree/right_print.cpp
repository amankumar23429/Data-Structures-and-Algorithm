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

node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();

        if(temp==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
        
            if(temp->left!=NULL){
                q.push(temp->left);
            }

            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

void rightPrint(node* root, int level, int &maxlevel){
    if(root==NULL){
        return;
    }

    if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel = level;
    }
    
    rightPrint(root->right, level+1, maxlevel);
    rightPrint(root->left, level+1, maxlevel);
    return;
}


int main (){
    node* root = buildTree();
    int maxlevel = -1;
    bfs(root);
    cout<<endl;
    rightPrint(root, 0, maxlevel);
    //node* root = createTreeFromTrav(preorder, inorder, 0, n-1);
    //bfs(root);
    return 0;
}