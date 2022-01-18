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

node* lca(node* root, int a, int b){
    if(root==NULL){
        return NULL;
    }

    if(root->data == a or root->data == b){
        return root;
    }

    node* leftAns = lca(root->left, a, b);
    node* rightAns = lca(root->right, a, b);

    if(leftAns!=NULL and rightAns!=NULL){
        return root;
    }

    if(leftAns!=NULL){
        return leftAns;
    }

    return rightAns;
}

int search(node* root, int level, int key){
    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return level;
    }

    int left = search(root->left, level+1, key);
    if(left!=-1){
        return left;
    }

    int right = search(root->right, level+1, key);
    return right;
}

int shortestDistance(node* root, int a, int b){
    node* lca_node = lca(root, a, b);
    int l1 = search(lca_node, 0, a);
    int l2 = search(lca_node, 0, b);
    return l1+l2;
}

int main (){
    node* root = NULL;
    levelOrderBuild(root);
    //bfs(root);

    cout<<shortestDistance(root, 7, 9)<<endl;
    
    return 0;
}