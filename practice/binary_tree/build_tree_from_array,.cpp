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

node* buildTree(int arr[], int s, int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(arr[mid]);

    root->left = buildTree(arr, s, mid-1);
    root->right = buildTree(arr, mid+1, e);

    return root;
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();

        if(temp==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
        
            if(temp->left!=NULL){
                q.push(temp->left);
            }

            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}


int main (){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    node* root = buildTree(arr, 0, n-1);
    bfs(root);
    return 0;
}