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

void insertAtTail(Node *&head, int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node *tail = head;

    while(tail->next!=NULL){
        tail = tail->next;
    }

    tail->next = new Node(d);
    return;
}

int length(Node *head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

void insertAtMiddle(Node *&head, int d, int p){
    if(head==NULL){
        head = new Node(d);
    }
    else if(length(head)<p){
        insertAtTail(head, d);
    }
    else{
        Node *temp = head;
        for(int i = 0; i<p-1; i++){
            temp = temp->next;
        }
        Node *n = new Node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<endl;

        head = head->next;
    }
}

void deleteAtHead(Node *&head){
    if(head==NULL){
        return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
}

bool search(Node*head, int key){
    while(head!=NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

//recursive search function
bool recursive_search(Node*head, int key){
    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }else{
        return recursive_search(head->next, key);
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

// It takes O(N) time complexity and O(1) space complexity
void reverse(Node*&head){
    Node *prev = NULL;
    Node *curr = head;
    Node *Next;

    while(curr!=NULL){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    head = prev;
}

//It takes O(N) time complexity and O(N)stack space complexity

Node* recReverse(Node *head){
    //base case
    if(head->next==NULL or head==NULL){
        return head;
    }
    //recursive approach
    Node* shead = recReverse(head->next);
    // Node* temp = shead;
    // while(temp->next!=NULL){
    //     temp = temp->next;
    // }
    // head->next = NULL;
    // temp->next = head;
    Node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return shead;
}

Node* midpoint(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL and fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;
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
    if(a->data<b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

Node* mergeSort(Node* head){
    // base case
    if(head==NULL or head->next==NULL){
        return head;
    }

    // step 1 divide
    Node* mid = midpoint(head);
    Node* a = head;
    Node* b = mid->next;
    mid->next = NULL;

    // step 2 sort
    a = mergeSort(a);
    b = mergeSort(b);

    // step 3 merge
    Node* c = merge(a,b);
    return c;
}


bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

void breakCycle(Node *head){
    if(detectCycle(head)){
        Node* slow = head;
        Node* fast = head;
        Node* start = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                break;        
            }
        }
        slow = start;
        while(slow->next!=fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

int main(){

    // Node *head = NULL;
    // insertAtHead(head, 4);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 8);
    // insertAtMiddle(head, 3, 3);
    // insertAtTail(head, 7);
    // deleteAtHead(head);
    // cout<<recursive_search(head, 3);

    //print(head);

    //Node *head = take_input();
    // Node *head;
    // cin>>head;
    // cout<<head;
    // head = recReverse(head);
    // cout<<head;
    // Node *mid = midpoint(head);
    // cout<<mid->data;

    // Node *a;
    // Node *b;
    // cin>>a;
    // cin>>b;

    // Node*head = merge(a,b);
    // cout<<head;

    // for mergesort
    // Node* head;
    // cin>>head;
    // head = mergeSort(head);
    // cout<<head;
    Node* head;
    cin>>head;
    Node* cycle = head->next->next;
    Node *tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }

    tail->next = cycle;

    cout<<detectCycle(head);
    
    breakCycle(head);
    cout<<head;
    return 0;
}