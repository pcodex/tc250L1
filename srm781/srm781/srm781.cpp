// srm781.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
srm 781 250
i didn't solve it during the contest and my score dipped to 580

given N
you have a set of number from 1 to 8N
you must use exactly 2N numbers from the set to obtain a sum of 4*N*N.

Return a string of size 8N containing a 1 for whichever number has been used 

so for N=2
set is 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
4*N*N = 16
2*N = 4
//actual nos are 1,2,4,9
string would be 1101000010000000

*/


#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

class EasyPartition
{
public:
	string getPartition(int N);
};

string EasyPartition::getPartition(int N)
{
	if (N == 1)
		return "10100000";

	int maxval = 8 * N;
	int maxentries = 2 * N;
	int target = 4 * N*N;

	int partialsum = 0;
	vector<int> theentries;
	for (int i = 0; i < maxentries - 2; ++i)
	{
		theentries.push_back(2* (i + 1));
		partialsum += (2 * (i + 1));
	}

	theentries.push_back(1);
	partialsum += 1;
	theentries.push_back(target - partialsum);
	
	string ansk = string(maxval, '0');
	for (int j = 0; j < theentries.size(); ++j) {
		ansk[theentries[j]-1] = '1';
	}

	return ansk;
}

int main()
{
	EasyPartition eps;
	string out = eps.getPartition(4);
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
