/*

Problem Statement
    
Alice has invited her two best friends, Charlie and Eric, to her birthday party. She has K boxes containing gifts for them. The boxes are numbered from 1 to K. For each i, box number i contains Fi gifts, where Fi is the ith Fibonacci number. (F1 = 1, F2 = 1, and for each i > 2, Fi = Fi - 1 + Fi - 2.)
Alice likes both of her friends equally, so she wants to distribute these K boxes between them in such a way that both of them get an equal total number of gifts. If that is possible, return a vector <int> containing box numbers which one of the two friends should receive. Note that all the boxes not chosen for this friend automatically go to the other friend. If there are multiple answers, you may return any of them.
If there is no solution, return the vector <int> {-1} instead i.e. an array with -1 as its only element.
Definition
    
Class:
AlicesBirthday
Method:
partition
Parameters:
int
Returns:
vector <int>
Method signature:
vector <int> partition(int k)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
The first few Fibonacci numbers are 1, 1, 2, 3, 5, 8, 13, 21, ...
Constraints
-
K will be between 1 and 40, inclusive.
Examples
0)

    
3
Returns: {3 }
There are K = 3 boxes containing gifts. Box 1 contains F1 = 1 gift, box 2 contains F2 = 1 gift, and box 3 contains F3 = 2 gifts.
Giving boxes #1 and #2 to Charlie and box #3 to Eric means that each of them receives two gifts. The returned array represents the numbers of the boxes received by Eric in this solution.
{1, 2} and {2, 1} are two other valid return values for this test case.
1)

    
5
Returns: {5, 1 }
F1 + F5 = 1 + 5 = 6. F2 + F3 + F4 = 1 + 2 + 3 = 6.
2)

    
1
Returns: {-1 }
Since there is only one box containing a single gift, there is no way for Charlie and Eric to have an equal number of gifts.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <vector>
//#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class AlicesBirthday
{
	int getFib(int k);
	
public:	
	int getTotal(int k);
	vector <int> partition(int k);
};

int AlicesBirthday::getFib(int k)
{
	int val = 0;

	if (k == 1 || k==2)
		return 1;
	
	else
	{
		val = getFib(k - 1) + getFib(k - 2);
	}

	return val;
}

int AlicesBirthday::getTotal(int k)
{
	int sum = 0;
	for (int i = 1; i <= k; ++i)
	{
		sum += getFib(i);
	}

	return sum;
}

vector <int> AlicesBirthday::partition(int k)
{
	vector<int> out;

	int tot = getTotal(k);

	if (tot % 2 != 0)
	{
		vector<int> res = { -1 };
		return res;
	}
	else
	{
		int split = tot / 2;
		int num = getFib(k);
		out.push_back(k);

		k--;
		
		while (k > 1)
		{
			int nxt = getFib(k);
			if (nxt + num <= split) {
				out.push_back(k);
				num += nxt;
			}
			
			if (num == split)
				break;

			k--;
		}

	}


	return out;
}

int main()
{
	AlicesBirthday ab;
	vector<int> res = ab.partition(3);
	



	return 0;
}
