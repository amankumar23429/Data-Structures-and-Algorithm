#include<iostream>
#include<string>
using namespace std;

int main(){
    string s0;

    string s1 = "hello world";

    string s2("hello world");

    string s3(s1);

    string s4 = s1;

    char c[] = {'a', 'b', 'c', '\0'};
    string s5(c);

    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;

    if (s0.empty()){
        cout<<"s0 is a empty string";
    }

    //append
    s0.append("and I append to it");
    cout<<s0<<endl;
    s1 += " and something";
    cout<<s1<<endl;

    //erase
    cout<<s0.length()<<endl;
    s0.erase();
    cout<<s0.length()<<endl;

    //compare the two strings

    s0 = "apple";
    s1 = "mango";

    cout<<s0.compare(s1)<<endl; // if both are equal it returns 0 otherwise non zero

    if (s1>s0){
        cout<<"s1 is greater than s0"<<endl;
    }

    string s = "I want to drink water and tea";
    int a = s.find("tea");

    cout<<a<<endl;
    string word = "tea";
    int len = word.length();

    s.erase(a, a+len);

    cout<<s<<endl;

    //iterate over the characters in the string 

    for (int i = 0; i < s.length(); i++){
        cout<<s[i]<<endl;
    }

    //iterators

    for (auto it = s.begin(); it != s.end(); it++){
        cout<<(*it)<<endl; // "it" is the pointer
    }

    //for each loop
    for(auto c:s1){
        cout<<c<<endl;
    }



    return 0;
}