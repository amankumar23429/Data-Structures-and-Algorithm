#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* insertion(node* root, int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }

    if(data <= root->data){
        root->left = insertion(root->left, data);
    }
    else{
        root->right = insertion(root->right, data);
    }
    return root;
}

node* buildBST(){
    int d;
    cin>>d;
    node*root = NULL;
    while(d!=-1){
        root = insertion(root, d);
        cin>>d;
    }
    return root;
}

class LinkedList{
    public:
    node* head;
    node* tail;
};

LinkedList flatten(node *root){
    LinkedList l;
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }
    // leaf node
    if(root->left==NULL and root->right==NULL){
        l.head = root;
        l.tail = root;
        return l;
    }

    //left subtree is not null
    if(root->left!=NULL and root->right==NULL){
        LinkedList leftll = flatten(root->left);
        leftll.tail->right = root;
        l.head = leftll.head;
        l.tail = root;
        return l;
    }

    //right subtree is not null
    if(root->left==NULL and root->right!=NULL){
        LinkedList rightll = flatten(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;

        return l;
    }
    LinkedList leftll = flatten(root->left);
    LinkedList rightll = flatten(root->right);

    leftll.tail->right = root;
    root->right = rightll.head;
    
    l.head = leftll.head;
    l.tail = rightll.tail;
    return l;
}

int main (){
    node*root = buildBST();
    LinkedList l = flatten(root);
    node* temp = l.head;
    while(temp!=NULL){
        cout<<temp->data<<" "<<endl;
        temp = temp->right;
    }

    return 0;
}