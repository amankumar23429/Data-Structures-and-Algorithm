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

void levelOrderBuild(node*&root){
    int d;
    cin>>d;
    root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* n = q.front();
        q.pop();
        int c1, c2;
        cin>>c1>>c2;
        if(c1!=-1){
            n->left = new node(c1);
            q.push(n->left);
        }
        if(c2!=-1){
            n->right = new node(c2);
            q.push(n->right);
        }
    }
}

void levelOrderPrint(node* root){
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

int printAtDistanceK(node* root, node* target, int k){
    if(root==NULL){
        return -1;
    }

    if(root==target){
        printAtLevelK(target, k);
        return 0;
    }
    // next step - ancestor
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
    
    int dr = printAtDistanceK(root->right, target, k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printAtLevelK(root->left, k-2-dr);
        }
        return dr+1;
    }
    return -1;
}

int main() {
    node* root = NULL;
    levelOrderBuild(root);
    // node* root = bulidTree();
    node* target = root->left->left;
    //levelOrderPrint(root);
    printAtDistanceK(root, target, 2);
    return 0;
}
//1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1 