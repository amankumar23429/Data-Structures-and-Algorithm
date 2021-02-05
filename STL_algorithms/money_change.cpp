#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    return a<=b;
}

int main(){
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int n = sizeof(coins)/sizeof(int);
    int money ;
    cin>>money;
    
    // by using comparator function
    while(money>0){
        int lb = lower_bound(coins, coins+n,money,compare) - coins - 1;
        cout<<coins[lb]<<"  ";
        money = money - coins[lb];
    }

    while(money>0){
        int ub = upper_bound(coins, coins+n,money) - coins - 1;
        cout<<coins[ub]<<"  ";
        money = money - coins[ub];
    }



    return 0;


}