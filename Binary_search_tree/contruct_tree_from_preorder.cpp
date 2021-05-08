#include<iostream>
#include<algorithm>
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

int i = 0;
node* build_tree_from_preorder(int *preorder, int *inorder, int s, int e){
    if(s>e){
        return NULL;
    }
    int index = -1;
    node* root = new node(preorder[i]);
    for(int j = s; j<=e; j++){
        if(inorder[j] == preorder[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = build_tree_from_preorder(preorder, inorder, s, index-1);
    root->right = build_tree_from_preorder(preorder, inorder, index+1, e);
    return root;
}
int main(){
    int preorder[] = {5,3,1,7,6,8};
    int n = sizeof(preorder)/sizeof(int);
    int inorder[n];
    for(int i = 0; i<n; i++){
        inorder[i] = preorder[i];
    }
    sort(inorder, inorder+n);

    node* root = build_tree_from_preorder(preorder, inorder, 0, n-1);
    bfs(root);
    return 0;
}