// srm780.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


class ElevatorButtons
{
public:
	vector <int> nextStops(int currentFloor, int currentDirection, vector <int> buttonsPressed);
};

vector <int> ElevatorButtons::nextStops(int currentFloor, int currentDirection, vector <int> buttonsPressed)
{
	set<int, greater<int>> down;
	set<int> up;

	for (int i = 0; i < buttonsPressed.size(); ++i)
	{
		if (buttonsPressed[i] < currentFloor)
			down.insert(buttonsPressed[i]);
		else
			up.insert(buttonsPressed[i]);
	}
	vector<int> ordervisited;
	set<int>::iterator upit = up.begin();
	set<int>::iterator downit = down.begin();
	if (currentDirection == 1)
	{		
		for(upit;upit!=up.end();upit++)
			ordervisited.push_back(*upit);		
		
		for (downit; downit != down.end(); downit++)
			ordervisited.push_back(*downit);		
	}

	else if (currentDirection == -1)
	{
		for (downit; downit != down.end(); downit++)
			ordervisited.push_back(*downit);

		for (upit; upit != up.end(); upit++)
			ordervisited.push_back(*upit);		
	}

	return ordervisited;
}

int main()
{

	ElevatorButtons eb;
	vector<int> pushbtns = { 420, 570, 140, 230, 915, 820, 499, 820, 177 };
	vector<int> out = eb.nextStops(500, 1, pushbtns);

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
