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

void levelOrderBuild(node* &root){
    int d;
    queue<node*> q;
    cin>>d;
    if(d!=-1){
        root = new node(d);
        q.push(root);
    }
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            temp->left = new node(c1);
            q.push(temp->left);
        }

        if(c2!=-1){
            temp->right = new node(c2);
            q.push(temp->right);
        }
    }
}

void printAtLevelK(node* root, int k){
    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return;
}

int printAtDistanceK(node*root, node* target, int k){
    if(root==NULL){
        return -1;
    }

    if(root==target){
        printAtLevelK(root, k);
        return 0;
    }

    int dl = printAtDistanceK(root->left, target, k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printAtLevelK(root->right, k-2-dl);
        }
        return dl+1;
    }

    int rl = printAtDistanceK(root->right, target, k);
    if(rl!=-1){
        if(rl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printAtLevelK(root->left, k-2-rl);
        }
        return rl+1;
    }

    return -1;
}


int main (){
    node* root = NULL;
    levelOrderBuild(root);
    //bfs(root);
    node* target = root->left->left;
    printAtDistanceK(root, target, 3);
    return 0;
}