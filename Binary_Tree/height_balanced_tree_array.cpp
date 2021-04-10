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

node* buildTreeFromArray(int *arr, int s, int e){
    if(s>e){
        return NULL;
    }
    //recursive case
    int mid = (s+e)/2;
    node* root = new node(arr[mid]);
    root->left = buildTreeFromArray(arr, s, mid-1);
    root->right = buildTreeFromArray(arr, mid+1, e);

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
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    node* root = buildTreeFromArray(arr, 0, n-1);
    bfs(root);
    return 0;
}
