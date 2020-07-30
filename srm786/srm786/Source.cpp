/*

Problem Statement
    
There is a cuboid (a rectangular box) of dimensions L x B x H. Vivek and Jeel decided to play the game CUT THE CUBE.
In this game, the players make moves alternately and the player who cannot make a move loses. Vivek starts the game. Below we define a move.
A move consists of cutting a cuboid along the xy plane, the xz plane, or the yz plane (lengthwise, breadthwise or heightwise). The two new pieces must again have integer dimensions. Hence, a cut is only possible if the dimension that is being cut is still greater than 1.
Initially, there is only one cuboid, so Vivek must cut that one into two smaller pieces. Afterwards, Jeel must choose and cut one of those two pieces. Next, Vivek must cut one of the three cuboids he currently sees, and so on.
Find out who wins if they both play optimally. Return 1 if Vivek wins otherwise return 2.
Definition
    
Class:
CutTheCube
Method:
findWinner
Parameters:
int, int, int
Returns:
int
Method signature:
int findWinner(int L, int B, int H)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
L will be between 1 and 100,000, inclusive.
-
B will be between 1 and 100,000, inclusive.
-
H will be between 1 and 100,000, inclusive.
Examples
0)

    
1
1
1
Returns: 2
Since all dimensions are 1, Vivek cannot make any move and Jeel wins immediately.
1)

    
2
1
1
Returns: 1
In this case, Vivek can only cut the cuboid lengthwise. After this move Jeel will end up with two 1x1x1 cubes which cannot be cut further. Hence Vivek wins.
2)

    
2
2
1
Returns: 1

3)

    
97931
95210
92383
Returns: 1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class CutTheCube
{
public:
	int findWinner(int L, int B, int H);
};

int CutTheCube::findWinner(int L, int B, int H)
{
	bool ev = false;
	
	//if it's an even dimension then the 1st guy cuts last
	//if it's an odd dimension then the 2nd guy cuts last
	//take the product of the dimensions
	if (L % 2 == 0 || B%2 ==0 || H%2 ==0)
	{
		ev = true;		
	}	

	if (ev == true)
	{
		//winner is vivek
		return 1;
	}
	else
		return 2;

}

int main()
{
	CutTheCube ctc;

	int win = ctc.findWinner(97931,
		95210,
		92383);

	return 0;
}