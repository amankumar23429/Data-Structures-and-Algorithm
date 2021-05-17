#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Student{
    public:
    string firstName;
    string lastname;
    string roll_no;

    Student(string f, string l, string no){
        firstName = f;
        lastname = l;
        roll_no = no;
    }

    bool operator==(const Student &s) const{
        return s.roll_no==roll_no?true:false;
    }
};

class hashfn{
    public:
    size_t operator()(const Student &s) const{
        return s.firstName.length() + s.lastname.length();
    }
};

int main(){
    unordered_map<Student, int, hashfn> student_map;
    Student s1("Aman", "Kumar", "005");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Prateek", "Gupta", "030");
    Student s4("Rahul", "Kumar", "013");

    student_map[s1] = 100;
    student_map[s2] = 90;
    student_map[s3] = 80;
    student_map[s4] = 60;

    cout<<student_map[s2]<<endl;

    for(auto s:student_map){
        cout<<s.first.firstName<<" "<<s.first.lastname<<" "<<s.second<<endl;
    }
    
    return 0;
}

