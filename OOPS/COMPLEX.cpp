#include<iostream>
using namespace std;

class Complex{
    public:
    int real;
    int img;

    Complex(){
        real = 0;
        img = 0;
    }

    Complex(int a, int b){
        real = a;
        img = b;
    }

    void set_real(const int a){
        real = a;
    }

    void set_imag(const int b){
        img = b;
    }

    void print() const{
        if(img>0){
            cout<<real << " + " <<img << "i";
        }else{
            cout<<real << " - " <<-img << "i";
        }
        cout<<endl;
    }

    void add(const Complex &x){
        real += x.real;
        img += x.img;
    }

    void operator+(const Complex &x){
        real += x.real;
        img += x.img;
    }

    void operator!(){
        img *= -1;
    }

    int operator[](string s){
        if(s=="real"){
            return real;
        }else{
            return img;
        }
    }
};

istream& operator>>(istream &is, Complex &c){
    int r1, i1;
    is>>r1>>i1;
    c.set_real(r1);
    c.set_imag(i1);
    return is;
}

ostream& operator<<(ostream &os, Complex &c){
    c.print();
    return os;
}

int main(){
    Complex c1;
    c1.set_real(1);
    c1.set_imag(5);

    c1.print();
    Complex c2(2,3);
    c2.print();

    //c1.add(c2);
    c1+c2; // + operator overloading 
    c1.print();

    !c2; // ! operator overloading 
    c2.print();

    cout<<c1["real"]; // [] operator overloading
    cout<<endl;
    Complex c4, c5;
    cin>>c4>>c5;
    cout<<c4<<c5;
    return 0;
}