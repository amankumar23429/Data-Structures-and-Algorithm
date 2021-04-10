#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* bulidTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left = bulidTree();
    root->right = bulidTree();
    return root;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left); // ls - left subtree
    int rs = height(root->right);
    return max(ls, rs)+1;
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

    return max(op1, max(op2, op3));
}

// optimized approach
class Pair{
    public:
    int diameter;
    int height;
};

Pair fastDiameter(node* root){
    Pair p;
    if(root==NULL){
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height+right.height , max(left.diameter, right.diameter));
    return p;
}

int main() {
    node* root = bulidTree();
    cout<<fastDiameter(root).diameter<<endl;
    cout<<fastDiameter(root).height;
    return 0;
}
