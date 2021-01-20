#include<iostream>
using namespace std;
int main(){
    int i,j,a,x,b,z;
    cin>>a;
    cin>>b;
    for(i=1;i<=a;i++){ 
        x=a-i+1;
        for(j=1;j<=b;j++){
            z=x+2*(i-1);  
      
            if((j==x)||(j==z))
                cout<<"*";
       
            else
                cout<<" ";
            if(j==z)
            x=x+2*(a-2)+2;
         
        } cout<<endl; 
    }
}