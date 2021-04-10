#include <iostream>
#include<queue>
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
int i = 0;
node* createTreeFromTrav(int *inorder, int *preorder, int s, int e){
    if(s>e){
        return NULL;
    }
    // recursive case
    node* root = new node(preorder[i]);
    int index = -1;
    for(int j = s; j<=e; j++){
        if(preorder[i]==inorder[j]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTrav(inorder, preorder, s, index-1);
    root->right = createTreeFromTrav(inorder, preorder, index+1, e);
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

int main(){
    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(in)/sizeof(int);
    node* root = createTreeFromTrav(in, pre, 0, n-1);
    bfs(root);
    return 0;
}
