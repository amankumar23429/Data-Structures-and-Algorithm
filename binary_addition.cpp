#include<bits/stdc++.h>
using namespace std;

string binary_addition(long a , long b){

    int a_last = 0;
    int b_last = 0;
    int carry = 0;
    int s = 0;
    
    string str ;

    while (a>0 || b>0){
        a_last = a%10;
        b_last = b%10;

        a /= 10;
        b /= 10;

        if((a_last == 1 && b_last == 1) || (a_last == 0 && b_last == 0)){
            if(carry == 1){
                s = 1;
            }else{
                s = 0;
            }
        }else{
            if(carry == 1){
                s = 0;
            }
            else{
                s = 1;
            }
        }

        str += to_string(s);

        if(a_last == 1 && b_last == 1){
            carry = 1;
        }

        if(a_last == 0 && b_last == 0){
            carry = 0;
        }
        
    }
    if(carry){
        str += to_string(1);
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(){
    string a = binary_addition(1100100111,11010010);
    cout<<a;
    return 0;
}