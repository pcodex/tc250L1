// srm782.cpp 
//
/*

Problem Statement
    
You are playing a game with Goblin Rabblemasters in Magic: the Gathering.
You are going to play T turns of the game. In the beginning of each turn you will add one new Goblin Rabblemaster to your army.
Goblin Rabblemaster is a creature with the following properties:
It attacks each turn, except for the turn it entered the game.
Whenever it attacks, it deals (2+G) damage, where G is the number of other goblins of any kind who attack that turn.
Each turn (including the turn it entered the game), immediately before your goblins attack, Goblin Rabblemaster adds an ordinary Goblin to your army.
An ordinary Goblin is a creature with the following properties:
It attacks each turn, including the turn when it entered the game.
Whenever it attacks, it deals 1 damage.
Calculate and return the total amount of damage your goblins will deal during the game.
Definition
    
Class:
GoblinRabblemaster
Method:
totalDamage
Parameters:
int
Returns:
long long
Method signature:
long long totalDamage(int T)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
T will be between 1 and 47,000, inclusive.
Examples
0)

    
1
Returns: 1
Turn 1: You add a Goblin Rabblemaster. The Rabblemaster adds an ordinary Goblin. The Goblin attacks and deals 1 damage.
1)

    
3
Returns: 33
Turn 1: You add a Goblin Rabblemaster. The Rabblemaster adds an ordinary Goblin. The Goblin attacks and deals 1 damage.
Turn 2: You add a second Goblin Rabblemaster. Each Rabblemaster adds an ordinary Goblin. Three Goblins and the first Rabblemaster attack together. Each Goblin deals 1 damage, and the Rabblemaster deals (2+3) = 5 damage.
Turn 3: You add a third Goblin Rabblemaster. Each Rabblemaster adds an ordinary Goblin. Six Goblins and two Rabblemasters attack. Each Rabblemaster sees 7 other attacking goblins and deals (2+7) = 9 damage.
Total damage dealt each turn is 1, 8, and 24 for a grand total of 33 damage.
2)

    
6
Returns: 336

3)

    
470
Returns: 6177551220
The answer for any valid test case is guaranteed to fit into a signed 64-bit integer variable. Watch out for integer overflow, variables with a smaller range of values are not sufficient.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <string>
#include <vector>
using namespace std;


class GoblinRabblemaster {
public:
	long long totalDamage(int T);
};

long long GoblinRabblemaster::totalDamage(int T) {

	long long mas = 0, gob = 0;
	long long masattackers = 0;
	long long gobattackers = 0;
	long long attscore = 0;

	for (int i = 0; i < T; ++i) {
		mas += 1;
		gob += mas;
		
		if (i > 1) {
			masattackers = (mas-2);
			gobattackers = gob;
		}
		else {
			gobattackers = gob;
		}
		long long totalattackers = masattackers + gobattackers;
		
		attscore += gobattackers + (mas - 1)*(2 + totalattackers);
	}

	return attscore;
}

int main()
{
	GoblinRabblemaster gmr;
	long long attacks = gmr.totalDamage(47000);

	return 0;    
}