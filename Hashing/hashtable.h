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