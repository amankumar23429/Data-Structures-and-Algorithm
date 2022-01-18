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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int leftMax = height(root->left);
    int rightMax = height(root->right);

    return max(leftMax, rightMax) + 1;
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);

    int op1 = h1+h2;

    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op1, op2));
}

class Pair{
    public:
    int height;
    int diameter;
};

Pair fast_diameter(node* root){
    Pair p;
    if(root==NULL){
        p.height = p.diameter = 0;
        return p;
    }

    Pair left = fast_diameter(root->left);
    Pair right = fast_diameter(root->right);

    p.height = max(left.height, right.height)+1;
    p.diameter = max((left.height+right.height), max(left.diameter, right.diameter));
    return p;
}

int main (){
    node* root = buildTree();
    Pair p = fast_diameter(root);
    cout<<p.diameter<<endl;
    cout<<p.height<<endl;
    return 0;
}