#include<iostream>
#include<cstring>
using namespace std;

class Car{
    private:
    float price;

    public:
    int model_no;
    char *name;

    Car(){
        name = NULL;
    }

    Car(float p, int m, char *n){
        price = p;
        model_no = m;
        name = new char[strlen(n)+1];
        strcpy(name, n);
    }
    
    // Deep Copy
    Car(Car &x){
        price = x.price;
        model_no = x.model_no;
        //deep copy
        name = new char[strlen(x.name)+1];
        strcpy(name, x.name);
    }

    // Copy Assignment operator
    void operator=(Car &x){
        cout<<"copy assignment operator"<<endl;
        price = x.price;
        model_no = x.model_no;
        // deep copy
        name = new char[strlen(x.name)+1];
        strcpy(name, x.name);
    }

    void set_price(float p){
        float msp = 100;
        if(p>msp){
            price = p;
        }else{
            price = msp;
        }
    }

    void print(){
        cout << "Name " << name<<endl; 
        cout << "Model no " << model_no<<endl; 
        cout << "Price " << price <<endl;
    }

    ~Car(){
        if(name!=NULL){
            cout<<"destructing car "<<name<<endl;
            delete [] name;
        }
    }

};

int main(){
    char c[] = "Tata";
    Car a(100, 2020, c);
    Car b(a);
    a.print();
    
    b.name[0] = 's';
    b.print();

    //copy assignment operator
    Car d;
    d = a;
    d.set_price(500);
    d.print();

    //dynamically created car;
    Car *f = new Car(3234, 2015, "safari");
    f->print();

    //delete keyword to delete dynamically created car object
    delete f;

    return 0;
}