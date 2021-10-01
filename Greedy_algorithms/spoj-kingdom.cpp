#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t, width, height, towers;
    vector<int> v_x;
    vector<int> v_y;
    cin>>t;
    while(t--){ 
        cin>>width>>height>>towers;
        int x, y;   
        for(int i = 0; i<towers; i++){
            cin>>x>>y;
            v_x.push_back(x);
            v_y.push_back(y);
        }
        sort(v_x.begin(), v_x.end());
        sort(v_y.begin(), v_y.end());

        int x_max = 0;
        int y_max = 0;
        int start_x = 0;
        int start_y = 0;
        int current = 0;
        for(int i = 0; i<towers; i++){
            current = v_x[i]-start_x-1;
            x_max = max(x_max,current);
            start_x = v_x[i];

            current = v_y[i]-start_y-1;
            y_max = max(y_max,current);
            start_y = v_y[i];
        }if(towers==0){
            int ans = height*width;
            cout<<ans<<endl;
        }
        else{
            current = width - v_x[towers-1];
            x_max = max(x_max,current);
            
            current = height - v_y[towers-1];
            y_max = max(y_max,current);
            int ans = x_max*y_max;
            cout<<ans<<endl;
        }
        v_x.clear();
        v_y.clear();
    }
    return 0;
}