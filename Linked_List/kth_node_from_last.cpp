#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node*n = new Node(d);
    n->next = head;
    head = n;
}

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<endl;

        head = head->next;
    }
}


Node* take_input(){
    int d;
    cin>>d;
    Node *head = NULL;
    while(d!=-1){
        insertAtHead(head, d);
        cin>>d;
    }
    return head;
}

istream& operator>>(istream &is, Node*&head){
    head = take_input();
    return is;
}

ostream& operator<<(ostream &os, Node*head){
    print(head);
    return os;
}

Node* KthNodeLast(Node* head, int k){
    Node* slow = head;
    Node* fast = head;
    int i = 0;
    while(i<k){
        fast = fast->next;
        i++;
    }

    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    int k;
    cin>>k;
    Node *head;
    cin>>head;
    Node *k_node = KthNodeLast(head, k);
    cout<<k_node->data;
    return 0;
}