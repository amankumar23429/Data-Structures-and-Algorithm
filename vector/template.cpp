#include<iostream>
using namespace std;

template<typename T>
class Vector{
    private:
    int cs;
    T *arr;
    int max_size;

    public:
    Vector(int default_size = 1){
        max_size = default_size;
        arr = new T[max_size];
        cs = 0;
    }

    void reserve(const int n){
        max_size = n;
    }

    void push_back(const T data){
        if(cs==max_size){
            T *old = arr;
            max_size = max_size*2;
            arr = new T[max_size];
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

    T front() const{
        cout<<arr[0]<<endl;
    }

    T back() const{
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

    T& operator[](const int i){
        return arr[i];
    }
};
template<typename X>
ostream& operator <<(ostream &os, const Vector<X> v){
    v.print();
    return os;
}
template<typename X>
istream& operator >>(istream &is, Vector<X> v){
    int val;
    is>>val;
    v.push_back(val);
    return is;
}

int main(){
    Vector<int> v;
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