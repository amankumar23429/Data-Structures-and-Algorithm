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
	double x = 2.43;
	double y = 1.2;
	return 0;
}
