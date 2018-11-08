/*************************************************************************
 * AUTHOR(S)	 : Chris Millones
 * STUDENT IDS   : 361396 & --------
 * Lab #		 : ------
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : -------
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "      Christopher Millones & \n";
	cout << setw(10) << "Lab #:  2\n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: " << "      Mondays & Wednesday: 3:00 - 6:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      -----\n";
	cout << "********************************************************\n\n";
}


const void INSTRUCTIONS() {

	cout << left;
	cout << "Write a recursive function that takes a string as an argument and\n"
			"returns a TRUE if the string is a palindrome otherwise FALSE is\n"
			"returned.\n\n";
}


bool palindromeCheck(int head, int tail, string word);
int main() {

	PRINTAUTHOR();
	INSTRUCTIONS();
	fstream inFile;
	vector<string> wholeContainer;
	string temp;
	string temp1 = "";
	string temp2;
	int head = 0;
	int tail = 0;
	bool isPalindrome;
	inFile.open("data.txt");


	while(!inFile.eof())
	{
		getline(inFile, temp);

		for( unsigned int i = 0; i <= temp.size()-1; i++)
		{
			if(isalpha(temp[i]) != 0)
			{
				temp2 = tolower(temp[i]);
				temp1 = temp1 + temp2;
			}
		}

		tail = temp1.size()-1;
		isPalindrome = palindromeCheck(head,tail,temp1);

		if(isPalindrome)
		{
			cout << temp << " Is a palindome!\n";
		}
		else
		{
			cout << temp << " Is NOT a palindrome\n";
		}

		temp1.clear();
	}

	return 0;
}

bool palindromeCheck(int head, int tail, string word)
{
	if(word[head] == word[tail])
	{
		head++;
		tail--;
		if(head > tail)
		{
			return true;
		}
		else if (head == tail)
		{
			return true;
		}
		palindromeCheck(head,tail,word);
	}else
	{
		return false;
	}
}
