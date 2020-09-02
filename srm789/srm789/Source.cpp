/*

Problem Statement
    
Here's the beginning of an ASCII art bitmap that depicts a tape measure:
###################################################
# # # # # # # # # # # # # # # # # # # # # # # # # #
#         #         #         #         #         #
#                   #                   #
0                   10                  20
A more formal description:
The first row is full of '#' marks and represents the top edge of the tape measure.
The second row shows unit marks in every second column.
Multiples of five get a longer mark that continues into the third row.
Multiples of ten get a mark that reaches all the way into the fourth row, and they also get labels in the fifth row. The label always begins in the column with the mark and extends to the right as needed.
You are given the ints leftMark and rightMark. Construct the drawing of the part of the tape measure that begins with the column containing the mark for number leftMark and ends with the column that contains the mark for the number rightMark. Return the drawing as a vector <string>.
Definition
    
Class:
TapeMeasure
Method:
draw
Parameters:
int, int
Returns:
vector <string>
Method signature:
vector <string> draw(int leftMark, int rightMark)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
leftMark will be between 0 and 999, inclusive.
-
rightMark will be between leftMark and 999, inclusive.
-
rightMark - leftMark will be at most 25.
Examples
0)

    
0
25
Returns:
{"###################################################",
 "# # # # # # # # # # # # # # # # # # # # # # # # # #",
 "#         #         #         #         #         #",
 "#                   #                   #          ",
 "0                   10                  20         " }
This is the exact example shown in the problem statement.
1)

    
981
990
Returns:
{"###################",
 "# # # # # # # # # #",
 "        #         #",
 "                  #",
 "0                 9" }
Note how the labels for marks 980 and 990 are partially visible in this section of the tape measure.
Below we show a section of the tape measure that is one mark wider on each side (left=980, right=991) so that you can see these labels completely.
#######################
# # # # # # # # # # # #
#         #         #
#                   #
980                 990
2)

    
20
20
Returns: {"#", "#", "#", "#", "2" }

3)

    
31
38
Returns:
{"###############",
 "# # # # # # # #",
 "        #      ",
 "               ",
 "               " }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

class TapeMeasure
{
public:
    vector <string> draw(int leftMark, int rightMark);
};

vector <string> TapeMeasure::draw(int leftMark, int rightMark)
{    
    string str1, str2, str3, str4;
    vector<string> vs;

    int noof2rowmarks = rightMark - leftMark + 1;
    int firstrowmarks = (noof2rowmarks * 2) - 1;

    str1 = string(firstrowmarks, '#');
    for (int i = leftMark; i <= rightMark; ++i)
    {
        if (i == rightMark)
            str2 += '#';        
        else
            str2 += "# ";
    }


    for (int j=leftMark; j <= rightMark; ++j)
    {
        if (j == rightMark && j%5==0)
            str3 += '#';
        else if (j % 5 == 0)
            str3 += "# ";
        else if (j == rightMark)        
            str3 += " ";        
        else
            str3 += "  ";
    }
    for (int j = leftMark; j <= rightMark; ++j)
    {
        if (j == rightMark && j%10==0)
            str4 += '#';
        else if (j % 10 == 0)
            str4 += "# ";
        else if (j == rightMark)
            str4 += " ";
        else
            str4 += "  ";
    }

    
    vs.push_back(str1);
    vs.push_back(str2);
    vs.push_back(str3);
    vs.push_back(str4);

    string s5;
    

    for (int i = leftMark; i <= rightMark; ++i)
    {

        if (i > 100 && i==leftMark) {

            if (((i - 1) % 10) == 0) {
                int val = i - 1;
                stringstream ssval;
                ssval << val;
                string strval = ssval.str();
                s5 = strval[2];
                s5 += " ";
                continue;
            }
            //continue;
        }

        
        if (i == rightMark && ((rightMark % 10) == 0))
        {
                stringstream ssi;
                ssi << rightMark;
                string strssi = ssi.str();
                s5 += strssi[0];
        }
        
        else if (i%10==0)
        {            
            stringstream ssi;
            ssi << i;
            string strssi = ssi.str();
            s5 += strssi;
            
            if (i == 0)
                s5 += " ";
        }
        else if (i == rightMark && (((i-1)%10)==0) && (i-1>=100))
        {
            continue;
        }
        else if(i==rightMark)
        {
            s5 += " ";
        }          
        else if((i==leftMark+1) && (leftMark%10==0) && (i>=100))
        {
            s5 += " ";
        }
        else if((i-1>=100) && ((i-1)%10==0))
        {
            s5 += " ";
        }
        else
        {
            s5 += "  ";
        }

    }
    
    vs.push_back(s5);

    return vs;
}

int main()
{
    TapeMeasure tpm;
    vector<string> out = tpm.draw(566, 579);

    return 0;
}