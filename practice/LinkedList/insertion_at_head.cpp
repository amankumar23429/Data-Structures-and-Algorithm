#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int d){
        data = d;
        next = NULL;
    }
};

void insertionAtHead(Node* &head, int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node* n = new Node(d);
    n->next = head;
    head = n;
    return;
}

void insertionAtTail(Node* &head, int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new Node(d);
    return;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int length(Node* head){
    int count = 0;
    while(head!=NULL){
        head = head->next;
        count++;
    }
    return count;
}

void insertAtMiddle(Node* &head, int d, int p){
    if(head==NULL){
        head = new Node(d);
    }
    else if(p>length(head)){
        
        insertionAtTail(head, d);
    }
    else{
        Node* temp = head;
        for(int i = 1; i<p; i++){
            temp = temp->next;
        }
        Node* n = new Node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteAthead(Node* &head){
    if(head==NULL){
        return;
    }
    Node* temp = head->next;
    delete head;
    head = temp;
}

void deleteAtTail(Node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        head = NULL;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    Node* tem = temp->next;
    delete tem;
    temp->next=NULL;



    return;
}

bool search(Node* head, int key){
    while(head!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

bool recursiveSearch(Node* head, int key){
    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }
    return recursiveSearch(head->next, key);
}

Node* input(){
    int d;
    cin>>d;
    Node* head = NULL;
    while(d!=-1){
        insertionAtTail(head, d);
        cin>>d;
    }
    return head;
}

istream& operator>>(istream &is, Node* &head){
    head = input();
    return is;
}

ostream& operator<<(ostream &os, Node* &head){
    print(head);
    return os;
}

void reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node* reverse_recursive(Node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    Node* shead = reverse_recursive(head->next);
    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return shead;
}

Node* midPoint(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* kthNode(Node* head, int k){
    Node* fast = head;
    Node* slow = head;
    int i = 0;
    while(i<k){
        fast = fast->next;
        i++;
    }

    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node* merge(Node* a, Node* b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    Node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

Node* mergesort(Node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    Node* mid = midPoint(head);
    Node* a = head;
    Node* b = mid->next;
    mid->next = NULL;

    a = mergesort(a);
    b = mergesort(b);

    Node* c = merge(a,b);
    return c;
}

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void breakCycle(Node* head){
    if(detectCycle(head)){
        Node* slow = head;
        Node* fast = head;
        Node* start = head;

        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }

        while(start->next!=slow->next){
            start = start->next;
            slow = slow->next;
        }
        slow->next = NULL;
    }
}

int main(){
    // Node* head = NULL;
    // insertionAtTail(head,2);
    // insertionAtTail(head,4);
    // insertionAtTail(head,6);
    // insertionAtTail(head,8);
    // insertionAtTail(head,9);
    // insertAtMiddle(head, 3, 1);
    //deleteAthead(head);
    //deleteAtTail(head);
    //cout<<search(head, 1);
    //print(head);
    //cout<<recursiveSearch(head, 6);
    //Node* head = input();
    // Node* head;
    // cin>>head;
    // head = reverse_recursive(head);
    //cout<<head;
    // Node* mid = midPoint(head);
    // cout<<mid->data;
    // Node* kNode = kthNode(head, 3);
    // cout<<kNode->data;

    // Node* a;
    // Node* b;
    // cin>>a;
    // cin>>b;
    // Node* head = merge(a,b);
    // cout<<head;

    // Node* head;
    // cin>>head;
    // head = mergesort(head);
    // cout<<head;

    Node* head;
    cin>>head;
    Node* cycle = head->next->next;
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = cycle;
    cout<<detectCycle(head)<<endl;
    breakCycle(head);
    cout<<detectCycle(head)<<endl;
    cout<<head;
    return 0;
}