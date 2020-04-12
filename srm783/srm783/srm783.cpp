// srm783.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

Problem Statement
    
This problem is about a specific way of rolling the dice in one franchise of tabletop RPG games.
Whenever the player attempts a non-trivial action, the action is evaluated as follows:
The game master sets the target value T based on the player's skill.
The game master gives the player some 6-sided dice to roll. Each die is either positive or negative.
The player rolls all the dice.
As long as there is a positive and a negative die with the same value, a pair of such dice is removed from the roll.
At this point, if there is a positive die with value less than or equal to the target, the roll is a success, otherwise it is a failure.
Each negative die that was not removed counts as a point of stress for the player.
You are given the target T and two vector <int>s: positiveDice and negativeDice. Return a vector <int> with two elements {X, Y}:
X should be 1 if the roll was a success and 0 if it was a failure.
Y should be the number of points of stress the roll produced.
Definition
    
Class:
PosNegDice
Method:
evaluateRoll
Parameters:
int, vector <int>, vector <int>
Returns:
vector <int>
Method signature:
vector <int> evaluateRoll(int T, vector <int> positiveDice, vector <int> negativeDice)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
T will be between 1 and 5, inclusive.
-
positiveDice will contain between 0 and 500 elements, inclusive.
-
negativeDice will contain between 0 and 500 elements, inclusive.
-
Each element of positiveDice will be between 1 and 6, inclusive.
-
Each element of negativeDice will be between 1 and 6, inclusive.
Examples
0)

    
1
{1, 6, 2}
{6}
Returns: {1, 0 }
The player rolled four dice: three positive dice and one negative die. The positive dice rolled 1, 6, and 2. The negative die rolled a 6.
After the roll, one pair of dice is removed: a positive die with value 6 and a negative die with value 6.
The player is left with two positive dice. These have values 1 and 2. As one of the dice is less than or equal to T = 1, the roll is a success.
As there are no negative dice left, the player does not receive any stress points.
1)

    
4
{}
{}
Returns: {0, 0 }
There are no dice at all, so the roll is automatically a failure (as there is no positive die with a value that is small enough). On the positive side, there is also no stress.
2)

    
4
{5, 6, 6, 5, 5}
{}
Returns: {0, 0 }
A failure (all positive dice rolled numbers that are bigger than the target) but with no stress.
3)

    
5
{3, 6, 3, 6}
{3, 3, 1, 3, 6, 3, 5}
Returns: {0, 4 }
Twice we remove a positive 3 and a negative 3. Once we remove a positive 6 and a negative 6. We are left with positiveDice = {6} and negativeDice = {1, 3, 3, 5}. The roll is a failure (the remaining positive die is too large) and the player receives four points of stress.
4)

    
4
{4, 5, 6}
{1, 2, 3}
Returns: {1, 3 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <algorithm>
#include <vector>
using namespace std;

class PosNegDice {
public:
	vector <int> evaluateRoll(int T, vector <int> positiveDice, vector <int> negativeDice);
};


vector <int> PosNegDice::evaluateRoll(int T, vector <int> positiveDice, vector <int> negativeDice) {

	vector<int> finpos;
	

	for (int i = 0; i < positiveDice.size(); ++i) {

		int val = positiveDice[i];
		if (find(negativeDice.begin(), negativeDice.end(), val) != negativeDice.end()) {
			positiveDice[i] = -1;
			auto pos = find(negativeDice.begin(), negativeDice.end(), val);
			negativeDice.erase(pos);
		}
	}

	int success = 0;
	for(int i=0;i<positiveDice.size();++i){
		if (positiveDice[i] <= T && positiveDice[i]!=-1) {
			success = 1;
			break;
		}		
	}

	finpos.push_back(success);
	finpos.push_back(negativeDice.size());

	return finpos;
}

int main()
{
	PosNegDice pds;
	vector<int> v1 = {1,6,2};
	vector<int> v2 = {6};

	vector<int> succ = pds.evaluateRoll(1, v1, v2);

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
