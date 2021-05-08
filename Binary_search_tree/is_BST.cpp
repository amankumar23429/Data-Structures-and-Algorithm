#include<iostream>
#include<climits>
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

bool isBST(node* root, int minV = INT_MIN, int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }

    if(root->data>=minV && root->data<=maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)){
        return true;
    }
    return false;
}

int main(){
    node *root = build_BST();
    if(isBST(root)){
        cout<<"tree is BST";
    }else{
        cout<<"tree is not BST";
    }
    return 0;
}