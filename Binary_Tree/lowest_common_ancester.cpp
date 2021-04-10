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

node* lca(node* root, int a, int b){
    if(root==NULL){
        return NULL;
    }
    if(root->data==a or root->data==b){
        return root;
    }

    node* leftAns = lca(root->left, a, b);
    node* rightAns = lca(root->right, a, b);
    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }

    if(leftAns!=NULL){
        return leftAns;
    }
    return rightAns;
}

int main() {
    node *root = bulidTree();
    cout<<"LCA of 6 and 9 is "<<lca(root, 6, 9)->data<<endl;
    cout<<"LCA of 4 and 7 is "<<lca(root, 4, 7)->data<<endl;
    return 0;
}
//1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1 