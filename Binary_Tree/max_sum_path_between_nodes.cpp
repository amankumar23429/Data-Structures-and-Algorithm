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

class Pair{
    public:
    int branchSum;
    int maxSum;

    Pair(){
        branchSum = 0;
        maxSum = 0;
    }
};

Pair maxSumPath(node* root){
    Pair p;
    if(root==NULL){
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    int op1 = root->data;
    int op2 = root->data + left.branchSum;
    int op3 = root->data + right.branchSum;
    int op4 = root->data + left.branchSum + right.branchSum;

    int current_ans_through_root = max(op1, max(op2,max(op3, op4)));

    //branch sum of the current root
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));
    return p;
}

int main(){
    node* root = bulidTree();
    cout<<maxSumPath(root).maxSum<<endl;
    return 0;
}
