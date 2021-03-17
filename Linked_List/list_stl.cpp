#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l1;
    //push back insert at tail of linked list
    l1.push_back(1);
    l1.push_back(2);
    //push front insert at front of linked list
    l1.push_front(0);
    
    //iteration in linked list
    for(auto x:l1){
        cout<<x<<" -> ";
    }
    cout<<endl;

    //list initialization with data
    list<string> l2{"aman", "kumar", "aman","sham", "ram"};

    for(auto x:l2){
        cout<<x<<" -> ";
    }

    cout<<endl;

    // remove function remove particular data in list
    l2.remove("aman");
    for(auto x:l2){
        cout<<x<<" -> ";
    }
    cout<<endl;

    // as we do not get position like array in list so we use this method to locate the particular location
    auto it = l2.begin();
    it++;

    // erase function erase data in particular position 
    l2.erase(it);
    for(auto x:l2){
        cout<<x<<" -> ";
    }
    cout<<endl;

    it = l2.begin();

    // insert take two arguments first is index and second is data
    l2.insert(it,"Aman");
    for(auto x:l2){
        cout<<x<<" -> ";
    }
    cout<<endl;
    return 0;
}