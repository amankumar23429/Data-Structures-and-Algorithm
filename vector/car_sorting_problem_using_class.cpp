#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Car{
    public:
    string name;
    int x;
    int y;
    
    Car(string name, int x, int y){
        this->name = name;
        this->x = x;
        this->y = y;
    }

    int dist(){
        return x*x + y*y;
    }
};

bool compare(Car c1, Car c2){
    int d1 = c1.dist();
    int d2 = c2.dist();
    if(d1==d2){
        return c1.name<c2.name;
    }
    return d1<d2;
}



int main(){
    vector<Car> c;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        string s;
        int x,y;
        cin>>s>>x>>y;
        Car temp(s, x, y);
        c.push_back(temp);
    }

    sort(c.begin(), c.end(), compare);

    for(auto x:c){
        cout<<"Car "<<x.name<<" at location "<<x.x<<","<<x.y<<endl;
    }

    return 0;
}