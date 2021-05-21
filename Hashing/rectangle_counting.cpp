#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Point{
    public:
    int x;
    int y;
    Point(){

    }
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class Compare{
    public:
    bool operator()(Point p1, Point p2){
        if(p1.x==p2.x){
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};

int rec_counts(vector<Point> v){
    int n = v.size();
    set<Point, Compare> s;
    for(int i = 0; i<n; i++){
        s.insert(v[i]);
    }
    
    int ans = 0;

    for(auto it = s.begin(); it!=prev(s.end()); it++){
        for(auto jt = next(it); jt!=s.end(); jt++){
            Point p1 = *it;
            Point p2 = *jt;

            if(p2.x==p1.x or p1.y==p2.y){
                continue;
            }
            Point p3(p1.x, p2.y);
            Point p4(p2.x, p1.y);

            if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
                ans++;
            }
        }
    }
    return ans/2;
}

int main(){
    int n;
    cin>>n;
    vector<Point> v;
    int x,y;
    for(int i = 0; i<n; i++){
        cin>>x>>y;
        Point p(x,y);
        v.push_back(p);
    }

    cout<<rec_counts(v);
    return 0;
}