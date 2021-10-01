// #include<iostream>
// #include<stack>
// using namespace std;

// bool isValidExp(char *c){
//     stack<char> s;
//     for(int i = 0; c[i]!='\0'; i++){
//         char ch = c[i];
//         if(ch=='('){
//             s.push(ch);
//         }
//         else if(ch==')'){
//             if(s.empty() or s.top()!='('){
//                 return false;
//             }
//             s.pop();
//         }
//     }
//     return s.empty();
// }

// int main(){
//     char ch[100] = "((a+b)+(c-d+f))";
//     cout<<isValidExp(ch);
//     return 0;
// }


// C++ program to get minimum lines to cover
// all the points
#include <bits/stdc++.h>
using namespace std;

// Utility method to get gcd of a and b
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// method returns reduced form of dy/dx as a pair
pair<int, int> getReducedForm(int dy, int dx)
{
	int g = gcd(abs(dy), abs(dx));

	// get sign of result
	bool sign = (dy < 0) ^ (dx < 0);

	if (sign)
		return make_pair(-abs(dy) / g, abs(dx) / g);
	else
		return make_pair(abs(dy) / g, abs(dx) / g);
}

/* method returns minimum number of lines to
	cover all points where all lines goes
	through (xO, yO) */
int minLinesToCoverPoints(int points[][2], int N,
								int xO, int yO)
{
	// set to store slope as a pair
	set< pair<int, int> > st;
	pair<int, int> temp;
	int minLines = 0;

	// loop over all points once
	for (int i = 0; i < N; i++)
	{
		// get x and y co-ordinate of current point
		int curX = points[i][0];
		int curY = points[i][1];

		temp = getReducedForm(curY - yO, curX - xO);

		// if this slope is not there in set,
		// increase ans by 1 and insert in set
		if (st.find(temp) == st.end())
		{
			st.insert(temp);
			minLines++;
		}
	}

	return minLines;
}

// Driver code to test above methods
int main()
{
	int xO, yO;
	xO = 1;
	yO = 0;

	int points[][2] =
	{
		{1,4},
		{2,1},
		{0,-2},
		{4,1},
		{4,3},
        {-2,3},
        {-1,1}
	};

	int N = sizeof(points) / sizeof(points[0]);
	cout << minLinesToCoverPoints(points, N, xO, yO);
	return 0;
}
