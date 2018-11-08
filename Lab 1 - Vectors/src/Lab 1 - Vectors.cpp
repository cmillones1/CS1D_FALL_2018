/*************************************************************************
 * AUTHOR(S)	 : Chris Millones
 * STUDENT IDS   : 361396 & --------
 * Lab #		 : ------
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : -------
 ************************************************************************/

/*************************************************************************
 * Lab / Assignment Title.
 * _______________________________________________________________________
 *
 *
 *
 ************************************************************************/


#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string>
using namespace std;

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "      Christopher Millones & Jose Cardenas\n";
	cout << setw(10) << "Lab #:  1\n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: " << "      Mondays & Wednesday: 5:00 - 7:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      8/20/18\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "a.	Write a program that uses a random number generator to generate 20 three-digit integers\n"
			"b.	Store the random numbers in a vector\n"
			"c.	Sort the random numbers\n"
			"d.	Reverse the digits of the random numbers\n"
			"e.	Store the reversed digits in another vector\n"
			"f.	Sum the digits of the random numbers\n"
			"g.	Store the sums in another vector\n"
			"h.	Print all three vectors\n";
}



vector<string> ReverseDigits(vector<int> temp);
vector <int> SumDigits(vector<int> temp);
int main() {

	PRINTAUTHOR();
	INSTRUCTIONS();



	srand(time(NULL));
	int temp = 0;
	vector <int> storage;
	vector <string> temp1;
	vector <int> temp2;
	vector <int> temp3;
	for(int i = 0; i <= 19; i++)
	{
		temp = rand() % 899 + 100;
		storage.push_back(temp);
	}

	cout << "\n\tPART A & B \n";
	for(int i = 0; i <= storage.size()-1; i++)
	{
		cout << "Element [" << i + 1 << "] : " << storage.at(i) << endl;
	}

	temp3 = storage;

	cout << "\n\tPART C\n";
	sort(storage.begin(), storage.begin()+storage.size());

	for(int i = 0; i <= storage.size()-1; i++)
	{
		cout << "Element [" << i + 1 << "] : " << storage.at(i) << endl;
	}

	cout << "\n\tPART D&E \n";
	temp1 = ReverseDigits(storage);
	cout << "\n\tPART F&G \n";
	temp2 = SumDigits(storage);


	cout << "\n\tPART H\n";
	for(int i = 0; i<= storage.size()-1; i++)
	{
		cout << "Element [" << i + 1 << "] : "  << temp3.at(i) << endl;
	}
	cout << endl;

	for(int i = 0; i <= storage.size()-1; i++)
	{
		cout << "Element [" << i + 1 << "] : " << temp1.at(i) << endl;
	}

	cout << endl;
	for(int i = 0; i <= storage.size()-1; i++)
	{
		cout << "Element [" << i + 1 << "] : " << temp2.at(i) << endl;
	}




	return 0;
}

vector<int> SumDigits(vector<int> temp)
{
	vector<int> temp1;
	int temp2 = 0;
	int temp3 = 0;
	for(int i = 0; i<= temp.size()-1; i++)
	{
		temp2 = temp.at(i) % 10;
		temp3 += temp2;
		temp2 = temp.at(i) / 10;
		temp3 += temp2 % 10;
		temp2 = (temp.at(i) / 10) / 10;
		temp3 += temp2 ;

		cout << "The sum of the digits of " << temp.at(i) << " is " << temp3 << endl;
		temp1.push_back(temp3);
		temp2 = 0;
		temp3 = 0;
	}

	return temp1;

}

vector<string> ReverseDigits(vector<int> temp)
{
	int temp1 = 0;
	string temp2 = "";
	int temp3 = 0;
	vector<string> reverseVector;

	for(int i = 0; i<= temp.size()-1; i++)
	{
		temp1 = temp.at(i) % 10;
		if(temp1 == 0)
		{
			temp2 = temp2 + "0";
		}
		else
		{
			temp2 = temp2 + to_string(temp1);
		}
		temp3 = temp.at(i)/10;
		temp1 = temp1 * 10;
		temp1 = temp1 + temp3 % 10;
		if(temp3 % 10 == 0)
		{

			temp2 = temp2 + "0";
		}
		else
		{
			temp2 = temp2 + to_string(temp3 % 10);
		}

		temp3 = temp3/10;
		temp1 = temp1 + temp3 %10;

		if(temp3 %10 == 0)
		{
			cout << " HERE 3\n";
			temp2 = temp2 + "0";
		}
		else
		{
			temp2 = temp2 + to_string(temp3 %10);
		}

		reverseVector.push_back(temp2);
		temp2.clear();
	}
	for(int i = 0; i <= reverseVector.size()-1; i++)
	{
		cout << "Element [" << i + 1 << "] : " << reverseVector.at(i) << endl;
	}

	return reverseVector;

}
