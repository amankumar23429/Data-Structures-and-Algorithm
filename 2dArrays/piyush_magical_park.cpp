#include<iostream>
using namespace std;

int main(){
    char a[100][100];
    int m,n,min_strength, current_strength;
    cin>>m>>n>>min_strength>>current_strength;
    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }

    bool success = true;
    for(int i = 0; i<m; i++){
        for (int j = 0; j<n;j++){
            if (current_strength < min_strength){
                success = false;
                break;
            }
            char c = a[i][j];
            if (c=='.'){
                current_strength -= 2;
            }else if (c=='*'){
                current_strength += 5;
            }else{
                break;
            }
            if(j!=n-1){
                current_strength--;
            }
        }
    }
    if(success){
        cout<<"Yes"<<endl;
        cout<<current_strength;
    }
    


    return 0;
}

