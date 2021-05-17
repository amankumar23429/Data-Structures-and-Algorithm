#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string, int> m;

    // 1) insert 
    m.insert(make_pair("Mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    // update 
    m["Mango"] += 50;

    // 2) search

    string fruit;
    cin>>fruit;

    // 3) find
    auto it = m.find(fruit);
    if(it != m.end()){
        cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl;
    }
    else{
        cout<<"fruit is not present"<<endl;
    }


    // 4) erase
    m.erase(fruit);

    // 5) count it is the alternative of find function
    if(m.count(fruit)){
        cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl;
    }
    else{
        cout<<"fruit is not present"<<endl;
    }

    m["Litchi"] = 60;
    m["Pineapple"] = 80;

    for(auto it = m.begin(); it!= m.end(); it++){
        cout<<it->first<<" and "<<it->second<<endl;
    }

    for(auto p:m){
        cout<<p.first<<" : "<<p.second<<endl;
    }
    return 0;
}