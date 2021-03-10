#include<iostream>
using namespace std;

class Vector{
    private:
    int cs;
    int *arr;
    int max_size;

    public:
    Vector(int default_size = 1){
        max_size = default_size;
        arr = new int[max_size];
        cs = 0;
    }

    void reserve(const int n){
        max_size = n;
    }

    void push_back(const int data){
        if(cs==max_size){
            int *old = arr;
            max_size = max_size*2;
            arr = new int[max_size];
            for(int i = 0; i < cs; i++){
                arr[i] = old[i];
            }

            delete [] old;
        }
        arr[cs++] = data;
    }

    bool empty() const{
        return cs==0;
    }

    int front() const{
        cout<<arr[0]<<endl;
    }

    int back() const{
        cout<<arr[cs-1]<<endl;
    }

    void pop() {
        if(!empty()){
            cs--;
        }   
    }

    void print() const{
        for(int i = 0; i < cs; i++){
            cout<<arr[i]<<endl;
        }
    }

    int size() const{
        return cs;
    }

    int maxSize() const{
        return max_size;
    }

    int& operator[](const int i){
        return arr[i];
    }
};

ostream& operator <<(ostream &os, const Vector v){
    v.print();
    return os;
}

istream& operator >>(istream &is, Vector v){
    int val;
    is>>val;
    v.push_back(val);
    return is;
}

int main(){
    Vector v;
    cout<<v.maxSize()<<endl;
    v.push_back(3);
    v.push_back(53);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    cout<<v.maxSize()<<endl;
    v.print();
    v[2] = 8;
    cout<<v[2];

    return 0;
}