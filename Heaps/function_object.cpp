#include<bits/stdc++.h>
using namespace std;

class fun{
    public:
    void operator()(string s){
        cout<<"having fun with "<<s<<endl;
    }
};

int main(){
    fun f;
    f("C++"); // overloaded () operator = function call where f is an object
    return 0;
}