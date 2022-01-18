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


node* createTreeFromTrav(int preorder[], int inorder[], int s, int e, int &i){
    if(s>e){
        return NULL;
    }
    node* root = new node(preorder[i]);
    int idx = -1;
    for(int j = s; j<=e; j++){
        if(inorder[j]==preorder[i]){
            idx = j;
        }
    }
    i++;
    root->left = createTreeFromTrav(preorder, inorder, s, idx-1, i);
    root->right = createTreeFromTrav(preorder, inorder, idx+1, e, i);
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


int main (){
    int n;
    cin>>n;
    int preorder[n];
    int inorder[n];
    for(int i = 0; i<n; i++){
        cin>>preorder[i];
    }
    for(int i = 0; i<n; i++){
        cin>>inorder[i];
    }
    int i = 0;
    node* root = createTreeFromTrav(preorder, inorder, 0, n-1, i);
    bfs(root);
    return 0;
}