#include<bits/stdc++.h>
#include "hashtable.h"
using namespace std;

int main(){
    Hashtable<int> price_menu;
    price_menu.insert("Burger", 100);
    price_menu.insert("Pepsi", 90);
    price_menu.insert("Pizza", 150);
    price_menu.insert("Noodles", 120);
    price_menu.insert("Pasta", 40);

    price_menu.print();
    // int* price = price_menu.search("Pepsi");
    // if(price==NULL){
    //     cout<<"Not found"<<endl;
    // }else{
    //     cout<<*price<<endl;
    // }
    price_menu.erase("Pepsi");
    price_menu.print();
    return 0;
}

