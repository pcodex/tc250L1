/*

Problem Statement
    
Tokyo Olympics 2021 is scheduled to start from the opening ceremony in July 23rd, 2021.

Suzuki, a man who lives in Japan, is looking forward to seeing the opening ceremony. Now, he wants to calculate how many days are remaining to the opening ceremony. (For example, if the opening ceremony were tomorrow, there would be 1 day remaining.)

Today's date is given as a string today in the format "YYYY.MM.DD". Day and month numbers have an extra leading zero if necessary. Some examples:
If today's date is July 24th, 2020, today will be "2020.07.24".
If today's date is November 9th, 2020, today will be "2020.11.09".
If today's date is February 25th, 2021, today will be "2021.02.25".

For Suzuki, calculate and return how many days are remaining to the opening ceremony of Tokyo Olympics 2021.
Definition
    
Class:
NextOlympics
Method:
countDays
Parameters:
string
Returns:
int
Method signature:
int countDays(string today)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
In this problem, you will implement the class "NextOlympics" with a public function named "countDays" which takes a string today as a parameter and returns an integer value.
-
If you do not know about how to compete or how to write/compile/test/submit solutions, please refer to https://www.topcoder.com/community/competitive-programming/how-to-compete for detailed information about competing in SRM.
-
And, don't forget testing at least on the example cases! In Applet Arena, you can test all example cases at once using "Batch Test". In Web Arena, you can test all example cases by checking all of them in the Test Panel.
-
For testing on custom cases or attempting challenges in the Challenge Phase, the string you input should be enclosed in double quotes (""). For example, you can input "2020.07.24" including the quotes.
Constraints
-
The string today will represent a valid date (in Gregorian Calendar) from July 24th 2020 to July 23rd 2021, inclusive.
Examples
0)

    
"2020.07.24"
Returns: 364
TopCoder SRM 788 is taking place in July 24th, 2020. Here, Tokyo Olympics 2021 is less than one year from now! Given this, 364 days are remaining to the opening ceremony of the Olympics.  By the way, July 24th, 2020 is a holiday in Japan called "Sports Day". It's a holiday to celebrate the Olympics.
1)

    
"2020.11.09"
Returns: 256
In this example, "today" is November 9th, 2020. Here, 256 days are remaining until the Olympics begin. So, you should return 256 for this example. Suzuki has to wait 256 days for the opening ceremony.
2)

    
"2021.02.25"
Returns: 148
In this example, "today" is February 25th, 2021. Here, 148 days are remaining until the opening ceremony. Suzuki has to wait 148 days for the opening ceremony.
3)

    
"2021.07.23"
Returns: 0
In this example, "today" is July 23rd, 2021. It's the day of the opening ceremony of the Tokyo Olympics 2021. For this case, since there are 0 days remaining to the opening ceremony, you should return 0.
4)

    
"2020.12.31"
Returns: 204
In this example, "today" is December 31st, 2020. There are 204 days remaining to the opening ceremony.
5)

    
"2021.01.01"
Returns: 203
In this example, "today" is January 1st, 2021. There are 203 days remaining to the opening ceremony.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class NextOlympics
{
private:
	int getdaysinmonth(int amonth);
public:
	int countDays(string today);
};

int NextOlympics::countDays(string today) //2020.07.30
{
	string OlympicDate = "2021.07.23";
	string curDate = today;
	
	string strmonth = curDate.substr(5, 2);
	stringstream ssmonth(strmonth);
	int month = 0;
	ssmonth >> month;

	string strday = curDate.substr(8, 2);
	stringstream ssday(strday);
	int day = 0;
	ssday >> day;

	string stryr = curDate.substr(2, 2);
	stringstream ssyr(stryr);
	int yr = 0;
	ssyr >> yr;

	int daysleftincurrmonth = 0;
	if (yr == 21 && month == 7) {
		daysleftincurrmonth = 23 - day;
		return daysleftincurrmonth;
	}
	else
		daysleftincurrmonth = getdaysinmonth(month) - day;	

	int dayssum = 0;
	if (yr == 21) {
		for (int i = month + 1; i < 7; ++i)
		{
			dayssum += getdaysinmonth(i);
		}
	}
	else if (yr == 20)
	{
		for (int i = month + 1; i < 13; ++i)
		{
			dayssum += getdaysinmonth(i);
		}
		for (int i = 1; i < 7; ++i)
		{
			dayssum += getdaysinmonth(i);
		}
	}
		 
	dayssum += 23+daysleftincurrmonth;

	return dayssum;

}

int NextOlympics::getdaysinmonth(int amonth)
{
	int thedays = 0;
	switch (amonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		thedays= 31;
		break;

	case 4:
	case 6:
	case 9:
	case 11:	
		thedays= 30;
		break;
	case 2:
		thedays = 28;
		break;
	}
	return thedays;

}

int main()
{
	NextOlympics nol;
	//int days = nol.countDays("2021.01.01"); //203
	//int days = nol.countDays("2020.12.01"); //234
	int days = nol.countDays("2020.11.30"); //235

	return 0;

}