#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public:
    string key;
    T value;
    Node<T>*next;

    Node(string key, T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class Hashtable{
    Node<T>** table;
    int current_size;
    int table_size;

    int hashfn(string key){
        int idx = 0;
        int p = 1;
        for(int i = 0; i<key.size(); i++){
            idx = idx + (key[i]*p)%table_size;
            idx = idx % table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }

    int isPrime(int n){
        if(n==1){
            return 0;
        }
        if(n == 2){
            return 1;
        }
        if (n%2==0){
            return 0;
        }
        for(int i = 3; (i*i)<n; i+=2){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }

    int next_prime(int table_size){
        int n = table_size*2;
        while(!isPrime(n)){
            n++;
        }
        return n;
    }

    void rehash(){
        Node<T>** old_table = table;
        int old_table_size = table_size;
        table_size = next_prime(table_size);

        table = new Node<T>*[table_size];

        for(int i = 0; i<table_size; i++){
            table[i] = NULL;
        }
        current_size = 0;

        for(int i = 0; i<old_table_size; i++){
            Node<T>*temp = old_table[i];
            while(temp!=NULL){
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if(old_table!=NULL){
                delete old_table[i];
            }
        }
        delete [] old_table;       
    }

    public:
    Hashtable(int min_size = 7){
        table_size = min_size;
        current_size  = 0;
        table = new Node<T>*[table_size];
        for(int i = 0; i<table_size; i++){
        table[i] = NULL;
        }
    }

    void insert(string key, T value){
        int idx = hashfn(key);
        Node<T>*n = new Node<T>(key, value);
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        float loadFactor = current_size/(1.0*table_size);
        if(loadFactor>0.7){
            rehash();
        }
    }

    T* search(string key){
        int idx = hashfn(key);
        Node<T>* temp = table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void erase(string key){
        int idx = hashfn(key);
        Node<T>* temp = table[idx];

        if(temp->key==key && temp->next==NULL){
            table[idx]= NULL;
            delete temp;
        }
        
        if(temp->key==key && temp->next!=NULL){
            Node<T>* t = temp;
            table[idx] = temp->next;
            t->next = NULL;
            delete t;
        }

        while(temp->next!=NULL){
            if(temp->next->key==key){
                Node<T>* t = temp->next;
                temp->next = temp->next->next;
                t->next = NULL;
                delete t;
                break;
            }
            temp = temp->next;
        }
        current_size--;
    }

    T& operator[](string key){
        T *f = search(key);
        
        if(f==NULL){
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }

    void print(){
        for(int i = 0; i<table_size; i++){
            cout<<"bucket "<<i<<" ->";
            Node<T> *temp = table[i];
            while(temp!=NULL){
                cout<<temp->key<<"-->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
