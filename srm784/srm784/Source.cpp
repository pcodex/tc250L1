/*

Problem Statement
    
You are in charge of a team of N other people. Together, you are going to prepare decorations for a huge party. In order to do that, each of you needs to have a pair of scissors. You already have one, but none of your helpers do.
You have recently purchased N pairs of scissors from an online retailer. They just arrived, but there is a small issue: each pair of scissors is wrapped in plastic. Getting scissors out of the plastic wrap requires having another pair of scissors (that's not in plastic) and it takes 10 seconds.
Assume that everything other than opening the packages happens instantly. (I.e., whenever a new pair of scissors has been opened, somebody can take it and immediately start opening another box.)
Calculate and return the shortest amount of time (in seconds) in which it is possible to release all the scissors from their plastic wraps.
Definition
    
Class:
Scissors
Method:
openingTime
Parameters:
int
Returns:
int
Method signature:
int openingTime(int N)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
N will be between 1 and 10^9, inclusive.
Examples
0)

    
3
Returns: 20
At the beginning you have the only free pair of scissors. It will take you 10 seconds to open a box containing another pair of scissors. At this point in time you have two pairs of scissors that are free and two that are still in plastic. Both other boxes with scissors can now be opened at the same time: one by you and one by somebody who took the pair of scissors you just liberated.
1)

    
10
Returns: 40
One possible optimal schedule:
First 10 seconds: open one box. You now have 2 scissors free + 9 in boxes.
Second 10 seconds: open two boxes. You now have 4 scissors free + 7 in boxes.
Third 10 seconds: open two boxes. You now have 6 scissors free + 5 in boxes.
Fourth 10 seconds: open the remaining five boxes.
There are other ways to open all scissors in 40 seconds but there is no way to do it faster.
2)

    
1234
Returns: 110

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <vector>
#include <cmath>
#include <vector>
using namespace std;


class Scissors
{
public:
	int openingTime(int N);
};

int Scissors::openingTime(int N)
{
	int run = 1;
	int cnt = 0;

	while (run <= N)
	{
		run = run * 2;
		cnt += 1;
	}	
	int ans = cnt * 10;
	return ans;
}

int main()
{
	Scissors sc;
	int val = sc.openingTime(32);
	return 0;
}