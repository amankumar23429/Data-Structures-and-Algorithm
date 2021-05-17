#include<bits/stdc++.h>
#include "hashtable.h"
using namespace std;

int main(){
    Hashtable<int> price_menu;

    price_menu["Dosa"] = 60;
    
    //price_menu["Dosa"] += 10;
    cout<<"Price of dossa is "<<price_menu["Dosa"]<<endl;
    return 0;
}

