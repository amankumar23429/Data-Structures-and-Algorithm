#include<iostream>
#include<cstring>
using namespace std;

class Car{
    private: // access modifier private and public
    float price;

    public:
    int model_no;
    string name;

    // constructor
    Car(){
        cout<<"inside car constructor"<<endl;
    }

    // parameterized constructor
    Car(float p, int m, string c){
        price = p;
        model_no = m;
        name = c;
    }

    // Copy constructor
    Car(Car &x){
        cout<<"inside copy constructor"<<endl;
        price = x.price;
        model_no = x.model_no;
        name= x.name;
    }

    float give_discount(float d){
        return price*(1.0-d);  
    }

    void print(){
        cout << "Name " << name<<endl; 
        cout << "Model no " << model_no<<endl; 
        cout << "Price " << price <<endl;
    }

    //getter
    float get_price(){
        return price;
    }

    // setter
    void set_price(float p){
        float msp = 100;
        if(p>msp){
            price = p;
        }else{
            price = msp;
        }
    }

    ~Car(){
        cout<<"inside destructor "<<name<<endl;
    }
};

int main(){
    Car c;
    c.model_no = 2021;
    c.name = "Porshe";
    c.set_price(70);

    Car s(120, 2020, "lambo");
    // cout<<"enter the discount which you want to give"<<endl;
    // float discount;
    // cin>>discount;
    // c.give_discount(discount);
    c.print();
    s.print();

    Car e(s); // copy constructor
    e.set_price(545);
    e.print();
    
    //another way of calling copy constructor
    Car f = e;
    f.print();
    
    return 0;
}