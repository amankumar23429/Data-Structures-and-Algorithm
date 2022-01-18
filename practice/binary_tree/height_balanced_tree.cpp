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

int replaceSum(node* root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL and root->right==NULL){
        return root->data;
    }

    int temp = root->data;
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);
    root->data = leftSum + rightSum;
    return root->data + temp;
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

class HBpair{
    public:
    bool balanced;
    int height;
};

HBpair isBalanced(node* root){
    HBpair p;
    if(root==NULL){
        p.height=0;
        p.balanced=true;
        return p;
    }
    HBpair left = isBalanced(root->left);
    HBpair right = isBalanced(root->right);

    p.height = (left.height, right.height)+1;
    if(abs(left.height-right.height)>1 or left.balanced==false or right.balanced==false ){
        p.balanced = false;
    }
    else{
        p.balanced = true;
    }
    return p;
}

int main (){
    node* root = buildTree();
    cout<<isBalanced(root).balanced;
    return 0;
}