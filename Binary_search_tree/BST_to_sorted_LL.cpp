#include<iostream>
#include<climits>
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



node* insertion_in_BST(node* root, int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }

    if(data<=root->data){
        root->left = insertion_in_BST(root->left, data);
    }
    else{
        root->right = insertion_in_BST(root->right, data);
    }
    return root;
}

node* build_BST(){
    int data;
    cin>>data;
    node *root = NULL;

    while(data!=-1){
        root = insertion_in_BST(root, data);
        cin>>data;
    }
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

void printInorder(node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

class LinkedList{
    public:
    node* head;
    node* tail;
};

LinkedList flatten(node* root){
    LinkedList l;
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }
    // leaf node 
    if(root->left==NULL && root->right==NULL){
        l.head = l.tail = root;
        return l;
    }
    // left subtree is not null
    if(root->left!=NULL && root->right==NULL){
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    // right subtree is not null
    if(root->left==NULL && root->right!=NULL){
        LinkedList rightLL = flatten(root->left);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main(){
    node *root = build_BST();
    bfs(root);
    cout<<endl;

    LinkedList l = flatten(root);
    node* temp = l.head;

    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->right;
    }
    return 0;
}