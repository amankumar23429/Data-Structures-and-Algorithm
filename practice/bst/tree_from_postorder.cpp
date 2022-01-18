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

int i = 0;
node* buildTree_from_preorder(int* preorder, int* inorder, int s, int e){
    if(s>e){
        return NULL;
    }
    node* root = new node(preorder[i]);
    int index = -1;
    for(int j = s; j<=e; j++){
        if(inorder[j]==preorder[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = buildTree_from_preorder(preorder, inorder, s, index-1);
    root->right = buildTree_from_preorder(preorder, inorder, index+1, e);
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

int main (){
    int preorder[] = {5,3,1,7,6,8};
    int n = sizeof(preorder)/sizeof(int);
    int inorder[n];

    for(int j = 0; j<n; j++){
        inorder[j] = preorder[j];
    }

    sort(inorder, inorder+n);
    node* root = buildTree_from_preorder(preorder, inorder, 0, n-1);
    printInorder(root);
    return 0;
}