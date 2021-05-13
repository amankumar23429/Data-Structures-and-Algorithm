#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Person{
    public:
    string name;
    int age;
    

    Person(){
        
    }

    Person(string n, int a){
        name = n;
        age = a;
        
    }
};

class PersonCompare{
    public:
    bool operator()(Person A, Person B){
        return A.age < B.age;
    }
};

int main(){
    int n;
    cin>>n;
    cin.get();
    priority_queue<Person, vector<Person>, PersonCompare> pq;

    for(int i = 0; i<n; i++){
        string name;
        int age;
        cin>>name>>age;
        Person p(name, age);
        pq.push(p);
    }
    cout<<endl;

    //top 3 oldest person
    for(int i = 0; i<3; i++){
        Person p1 = pq.top();
        cout<<p1.name<<" "<<p1.age<<endl;
        pq.pop();
    }
    return 0;
}