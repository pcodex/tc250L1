// srm772.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

Problem Statement
    
Given count plus signs ('+'), arrange them in a way that maximizes the number of closed figures. Assume that horizontally or vertically adjacent plus signs touch each other.
For example, the following arrangement of 8 plus signs contains three closed figures (squares, each formed by parts of four + signs):
++++
++++
The following arrangement contains 10 plus signs but only one closed figure (a 2x3 rectangle with some short line segments on the inside):
++++
+  +
++++
And the following arrangement of 6 plus signs contains no closed figures at all:
+ + +
 + ++
Compute and return the largest number of closed figures that can be produced using exactly count plus signs.
Definition
    
Class:
PlusCastle
Method:
maximiseClosedFigures
Parameters:
int
Returns:
int
Method signature:
int maximiseClosedFigures(int k)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
count will be between 1 and 1,000,000,000, inclusive
Examples
0)

    
9
Returns: 4
The following arrangement maximises the number of closed figures: +++ +++ +++
1)

    
6
Returns: 2
The following arrangement maximises the number of closed figures: +++ +++
2)

    
898680485
Returns: 898620529

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class PlusCastle
{
public:
	int maximiseClosedFigures(int k);
};

int PlusCastle::maximiseClosedFigures(int k)
{
	int ans = 0;
	int val = sqrt(k);	
	
	if ((val*val) == k)
		ans = (val - 1)*(val - 1);
	else {
		int rndval = sqrt(k);  //3
		
		int startans = (rndval - 1)*(rndval - 1);  //4
		int rndvalsq = rndval * rndval;

		//int diff = k - rndvalsq;  //2
		
		for (int i = rndvalsq+1; i <= k; ++i) {
			if ((i == rndvalsq+1)||(i == rndvalsq + rndval+1))
				continue;

			startans += 1;
			if (i == k) 
				break;			
		}

		ans = startans;
	}
	
	return ans;
}

int main()
{
	PlusCastle pcs;
	int val = 35;
	int ans = pcs.maximiseClosedFigures(val);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
