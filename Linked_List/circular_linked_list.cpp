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

void insertAtHead(Node*&head, int d){
    Node *n = new Node(d);
    n->next = head;
    Node* temp = head;

    if(temp!=NULL){
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = n;
    }
    else{
        n->next = n;
    }
    head = n;
}

void print(Node*head){
    Node* temp = head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<" ";
}

Node* getNode(Node* head, int d){
    Node*temp = head;
    while(temp->next!=head){
        if(temp->data==d){
            return temp;
        }
        temp = temp->next;
    }
    if(temp->data==d){
        return temp;
    }
    return NULL;
}

void deleteNode(Node*&head, int d){
    Node* del = getNode(head, d);
    if(del==NULL){
        return;
    }

    if(head==del){
        head = head->next;
    }

    Node*temp = head;
    while(temp->next!=del){
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}


int main(){
    Node* head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    deleteNode(head, 2);
    print(head);
    cout<<endl;
    deleteNode(head, 1);
    print(head);
    return 0;
}