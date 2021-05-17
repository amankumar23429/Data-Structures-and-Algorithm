#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;


int main(){
    unordered_map<string, vector<string>> phonebook;
    phonebook["rahul"].push_back("132244");
    phonebook["rahul"].push_back("434533");
    phonebook["rahul"].push_back("967594");
    phonebook["rahul"].push_back("048300");

    phonebook["ayush"].push_back("132424");
    phonebook["shivam"].push_back("130485");

    for(auto x:phonebook){
        cout<<"Name "<<x.first<<"-> ";
        for(auto s:x.second){
            cout<<s<<",";
        }
        cout<<endl;
    }

    string name;
    cin>>name;

    if(phonebook.count(name)){
        for(auto r:phonebook[name]){
            cout<<r<<" , ";
        }
        cout<<endl;
    }else{
        cout<<"absent";
    }
    return 0;
}

