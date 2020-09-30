/*
srm 383
Problem Statement
    
You are building a house and are about to lay the floorboards in a particular room. Your architect has designed the layout of the floorboards and you now want to know how many boards you need to buy. Each board is 1 unit wide and can be of any positive integer length. The room is rectangular and the boards are to be laid out on a unit-square grid inside the room, parallel to the walls of the room.

You are given a vector <string> layout describing the layout of the floorboards. Character j of element i of layout describes the grid-square at position (i, j) and will either be a '-' or a '|', depending on which direction the floorboard covering that square is oriented. If two '-' characters are adjacent at the same value of i, then they form part of the same east/west-oriented floorboard. Similarly, if two '|' characters are adjacent at the same value of j, they are part of the same north/south-oriented floorboard. Return an int containing the number of distinct floorboards in the layout.
Definition
    
Class:
FloorLayout
Method:
countBoards
Parameters:
vector <string>
Returns:
int
Method signature:
int countBoards(vector <string> layout)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
layout will contain between 1 and 50 elements, inclusive.
-
Each element of layout will contain between 1 and 50 characters, inclusive.
-
Each element of layout will contain the same number of characters.
-
Each character in layout will be a '-' or a '|'.
Examples
0)

    
{"----"
,"----"
,"----"
,"----"}
Returns: 4
This layout contains 4 boards laid east/west.
1)

    
{"-||--||--"
,"--||--||-"
,"|--||--||"
,"||--||--|"
,"-||--||--"
,"--||--||-"}
Returns: 31
This is an aesthetic pattern made up of boards of lengths 1 and 2.
2)

    
{"--------"
,"|------|"
,"||----||"
,"|||--|||"
,"||----||"
,"|------|"
,"--------"}
Returns: 13

3)

    
{"||-||-|||-"
,"||--||||||"
,"-|-|||||||"
,"-|-||-||-|"
,"||--|-||||"
,"||||||-||-"
,"|-||||||||"
,"||||||||||"
,"||---|--||"
,"-||-||||||"}
Returns: 41

4)

    
{"-||--|"
,"||||||"
,"|||-|-"
,"-||||-"
,"||||-|"
,"||-||-"}
Returns: 19

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class FloorLayout
{
public:

	int countBoards(vector <string> layout);

};

int FloorLayout::countBoards(vector <string> layout)
{
	int tot = 0;
	
	for (int i = 0; i < layout.size(); i++) {
		int j = 0;
		while (j < layout[i].length()) {			
			string curr = layout[i];
			while (curr[j] == '-' && j < layout[i].length())
			{
				j++;
			}
			if (j>0 && curr[j - 1] == '-')
				tot += 1;
			j++;
		}
	}


	for (int i = 0; i < layout[0].size(); i++) {
		int j = 0;
		while (j < layout.size()) {
			char curr = layout[j][i];
			while (curr == '|' && j < layout.size())
			{
				j++;

				if(j<layout.size())
					curr = layout[j][i];
			}
			if (j > 0 && layout[j-1][i] == '|')
				tot += 1;
			j++;
		}
	}

	return tot;
}

int main()
{
	
	FloorLayout fl;
	vector<string> vs1 = 
	{ "----"
,"----"
,"----"
,"----" };

	vector<string> vs2 =
	{ "-||--||--"
,"--||--||-"
,"|--||--||"
,"||--||--|"
,"-||--||--"
,"--||--||-" };

	vector<string> vs3 =
	{ "--------"
	,"|------|"
	,"||----||"
	,"|||--|||"
	,"||----||"
	,"|------|"
	,"--------" };

	vector<string> vs4 =
	{ "||-||-|||-"
	,"||--||||||"
	,"-|-|||||||"
	,"-|-||-||-|"
	,"||--|-||||"
	,"||||||-||-"
	,"|-||||||||"
	,"||||||||||"
	,"||---|--||"
	,"-||-||||||" };

	vector<string> vs5 =
	{ "-||--|"
,"||||||"
,"|||-|-"
,"-||||-"
,"||||-|"
,"||-||-" };

	int out = fl.countBoards(vs1);
	out = fl.countBoards(vs2);
	out = fl.countBoards(vs3);
	out = fl.countBoards(vs4);
	out = fl.countBoards(vs5);

	return 0;

}