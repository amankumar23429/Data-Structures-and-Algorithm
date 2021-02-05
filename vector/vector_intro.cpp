#include<iostream>
#include<vector>
using namespace std;


int main(){

    // vector initialization

    vector<int> a;
    vector<int> b(5,1);  // b(n,i) where n is the number of size of vector b and i is the number assigned to each positon
    vector<int> c(b.begin(), b.end());
    vector<int> d{1,2,3,4,5};

    //interation of vectors

    for(int i = 0; i<c.size(); i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;

    for(auto it = c.begin(); it != c.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for(int x:d){
        cout<<x<<" ";
    }

    cout<<endl;

    // functions of vectors
    vector<int> v;
    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }

    for(int x:v){
        cout<<x<<" ";
    }

    cout<<endl;

    cout<<v.size()<<endl;        // size of the filled position in vector
    cout<<v.capacity()<<endl;    // size of underling array 
    cout<<v.max_size()<<endl;    // maximum no of elements that vector can hold in the worst case acc. to available memory


    cout<<d.size()<<endl;        
    cout<<d.capacity()<<endl;     
    cout<<d.max_size()<<endl;

    return 0;
}