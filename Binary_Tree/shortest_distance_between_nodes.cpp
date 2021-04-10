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

int search(node* root, int key, int level){
    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return level;
    }

    int left = search(root->left, key, level+1);
    if(left!=-1){
        return left;
    }
    return search(root->right, key, level+1);
}

int shortestDistance(node* root, int a, int b){
    node* lca_node = lca(root, a, b);

    int l1 = search(lca_node, a, 0);
    int l2 = search(lca_node, b, 0);

    return l1+l2;

}

int main() {
    node *root = bulidTree();
    cout<<shortestDistance(root, 4, 7);
    return 0;
}
//1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1 