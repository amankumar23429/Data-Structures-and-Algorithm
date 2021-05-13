#include <bits/stdc++.h>
using namespace std;
 
class Point{
	pair<int, int> p1;
	pair<int,int> p2;

	public:
	Point(pair<int, int> p1, pair<int, int> p2){
		this->p1 = p1;
		this->p2 = p2;
	}
	 void display(){
		 cout<<p1.first+p2.first<<" "<<p1.second+p2.second<<endl;
	 }
};

int main(){
	int x1, y1, x2, y2;
	cin>>x1>> y1;
	cin>>x2>>y2;
	Point p(make_pair(x1,y1), make_pair(x2, y2));
	p.display();
	return 0;
}
