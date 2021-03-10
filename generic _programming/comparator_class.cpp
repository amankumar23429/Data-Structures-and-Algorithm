#include<iostream>
#include<list>
using namespace std;

class Book{
    public:
    string name;
    int price;

    Book(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class BookCompare{
    public:
    bool operator()(Book a, Book b){
        if(a.name==b.name){
            return true;
        }
        return false;
    }
};

template <class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp){
    while(start!=end){
        if(cmp(*start, key)){
            return start;
        }
        start++;
    }
    return end;
}

int main(){
    Book b1("C++", 100);
    Book b2("Java", 110);
    Book b3("Python", 120);
    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book bookToFind("C++", 120);
    BookCompare cmp;

    auto it = search(l.begin(), l.end(), bookToFind, cmp);

    if(it!=l.end()){
        cout<<"book is found in the library";
    }else{
        cout<<"not found in the library";
    }

    return 0;
}