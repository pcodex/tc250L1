// srm787.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*


Problem Statement
    
This problem is about a traditional way of naming the second child in a family. Aqa Asadi wants to name his second child this way.
All people in this problem have exactly two names, e.g., “Yasaman Sadat” or “Mohammad Reza”. In this problem, we will assume that the people whose first name starts with a vowel are female and all other people are male. Note that in this problem the letter Y is considered a vowel (so the vowels are A, E, I, O, U, and Y).
You are given the strings Dad, Mom and FirstChild: the names of a dad, a mom, and their first child. You are also given the string Gender: the gender of their second child (either "Boy" or "Girl"). Your task is to determine and return the name for the second child according to the rules given below.
If the gender of the first child differs from the second child, the second child will use both names of their parent with the same gender, in reversed order.
If both children have the same gender, the second child will get its first name from the parent with the same gender as itself (i.e., girls from their mom, boys from their dad) and its second name from its older sibling.
Definition
    
Class:
AqaAsadiNames
Method:
getName
Parameters:
string, string, string, string
Returns:
string
Method signature:
string getName(string Dad, string Mom, string FirstChild, string Gender)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Notes
-
You should always follow the rules in the problem statement, even if the name they produce does not match the child's gender (see Example #1) or produces the same name as the first child had (see Example #4).
Constraints
-
Each name (Dad, Mom, FirstChild) will contain at most 20 characters.
-
Each name will have the form "First Second", with exactly one space and with exactly the first letter of each name in uppercase.
-
Each name will only consist of uppercase and lowercase English letters (A-Z, a-z), and the single space between the two names.
-
Dad will start with a consonant and Mom will start with a vowel (AEIOUY).
-
Gender will be either "Boy" or "Girl".
Examples
0)

    
"Mohammad Reza"
"Yasaman Sadat"
"Baqer Ali"
"Boy"
Returns: "Mohammad Ali"
Both children are boys, so the second child gets his first name ("Mohammad") from his father and his second name ("Ali") from his brother.
1)

    
"Mohammad Reza"
"Yasaman Sadat"
"Baqer Ali"
"Girl"
Returns: "Sadat Yasaman"
The children have different genders. Thus, the second child's name is obtained by swapping her mother's two names.
Note that the returned name is not a proper name for a girl, but that's what the rules produced, so that's what you should return.
2)

    
"Mohammad Reza"
"Yasaman Sadat"
"Umi Kulsum"
"Girl"
Returns: "Yasaman Kulsum"
A case similar to Example #0, but this time the child gets her name by combining the names of her mother and her sister.
3)

    
"Mohammad Reza"
"Yasaman Sadat"
"Umi Kulsum"
"Boy"
Returns: "Reza Mohammad"

4)

    
"Mohammad Ali"
"Yasaman Sadat"
"Mohammad Reza"
"Boy"
Returns: "Mohammad Reza"

5)

    
"Dhikrullah Ali"
"Umi Kulsum"
"Reza Hosseinzadeh"
"Boy"
Returns: "Dhikrullah Hosseinzadeh"
Note that the second child's name can sometimes have more than 20 characters.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

class AqaAsadiNames
{
public:
    string getName(string Dad, string Mom, string FirstChild, string Gender);
};


string AqaAsadiNames::getName(string Dad, string Mom, string FirstChild, string Gender)
{
    string child1gender = "Boy";

    if (FirstChild[0] == 'A' || FirstChild[0] == 'E'
        || FirstChild[0] == 'I' || FirstChild[0] == 'O'
        || FirstChild[0] == 'U' || FirstChild[0] == 'Y')
    {
        child1gender = "Girl";
    }

    string child2name = "";

    if (child1gender != Gender)
    {
        if (Gender == "Girl")
        {
            size_t split = Mom.find(" ");
            string Momlname = Mom.substr(split+1, Mom.size());
            string Momfname = Mom.substr(0, split);
            child2name = Momlname + " " + Momfname;
        }
        else if (Gender == "Boy")
        {
            size_t split = Dad.find(" ");
            string Dadlname = Dad.substr(split+1, Dad.size());
            string Dadfname = Dad.substr(0, split);
            child2name = Dadlname + " " + Dadfname;
        }
    }
    else if (child1gender == Gender) {
        if (Gender == "Boy") {
            child2name = Dad.substr(0, Dad.find(" "));
            size_t pos = FirstChild.find(" ");
            string child1lname = FirstChild.substr(pos+1, FirstChild.size());
            child2name += " "+child1lname;
        }
        else if (Gender == "Girl") {
            child2name = Mom.substr(0, Mom.find(" "));
            size_t pos = FirstChild.find(" ");
            string child1lname = FirstChild.substr(pos+1, FirstChild.size());
            child2name += " "+child1lname;
        }

    }

    return child2name;
}

int main()
{
    AqaAsadiNames aa;
    string child2 = aa.getName("Mohammad Reza",
        "Yasaman Sadat",
        "Baqer Ali",
        "Girl");

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
