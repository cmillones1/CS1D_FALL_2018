
/*************************************************************************
 * AUTHOR(S)	 : Chris Millones
 * STUDENT IDS   : 361396 & --------
 * Lab #		 : ------
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 3:00 - 6:20PM
 * DUE DATE    	 : -------
 ************************************************************************/

/*************************************************************************
 * Prefix Averages
 * _______________________________________________________________________
 *	Implement prefixAverages1 and prefixAverages2
*	and perform an experimental analysis of their
 *	running time using multiple array (vector) sizes.
 *
 *	Method of Attack:
 *	Initiate 3 vectors with different sizes, yet these sizes increase
 *	dramatically. This causes the function of the prefix average to actually
 *	demonstrate in real time its true complexity.
 *
 *
 ************************************************************************/


#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <ctime>
using namespace std;

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "      Christopher Millones & Jose & Jake \n";
	cout << setw(10) << "Lab #:  3\n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: " << "      Mondays & Wednesday: 5:00 - 7:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      8/29/18\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "Implement prefixAverages1 and prefixAverages2\n"
			"and perform an experimental analysis of their\n"
			" running time using multiple array (vector) sizes.\n\n";
}



vector<int> PrefixAverage1(vector<int> temp);
vector<int> PrefixAverage2(vector<int> temp);
int main() {

	PRINTAUTHOR();
	INSTRUCTIONS();

	vector<int> smallVector;
	vector<int> medVector;
	vector<int> largeVector;

	vector<int> smallResult1;
	vector<int> medResult1;
	vector<int> largeResult1;

	vector<int> smallResult2;
	vector<int> medResult2;
	vector<int> largeResult2;

	for (int i = 0; i <= 40000; i++) {
		smallVector.push_back(i);
	}

	for (int i = 0; i <= 80000; i++) {
		medVector.push_back(i);
	}

	for (int i = 0; i <= 120000; i++) {
		largeVector.push_back(i);
	}

	std::clock_t start;
	double duration;

	/*
	 * *********************SMALL**************************************
	 */

	start = std::clock();
	smallResult1 = PrefixAverage1(smallVector);
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

	cout << "\tSmall PrefixAverage1\n";
	cout << "Input: 0 1 2 3 ...\n";
	cout << "Output: ";
	for (int i = 0; i <= 3; i++) {
		cout << smallResult1.at(i) << " ";
	}
	cout << "...\nTime(s): " << duration << endl << endl;

	/*
	 * *********************MEDIUM**************************************
	 */
	start = std::clock();
	medResult1 = PrefixAverage1(medVector);
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

	cout << "\tMeduim PrefixAverage1\n";
	cout << "Input: 0 1 2 3 ...\n";
	cout << "Output: ";
	for (int i = 0; i <= 3; i++) {
		cout << medResult1.at(i) << " ";
	}
	cout << "...\nTime(s): " << duration << endl << endl;

	/*
	 * *********************LARGE**************************************
	 */
	start = std::clock();
	largeResult1 = PrefixAverage1(largeVector);
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

	cout << "\tLarge PrefixAverage1\n";
	cout << "Input: 0 1 2 3 ...\n";
	cout << "Output: ";
	for (int i = 0; i <= 3; i++) {
		cout << largeResult1.at(i) << " ";
	}
	cout << "...\nTime(s): " << duration << endl << endl;

	/**********************************************************************************
	 ***********************************************************************************
	 ***********************************************************************************
	 ***********************************************************************************
	 ***********************************************************************************
	 ***********************************************************************************/

	/*
	 * *********************SMALL**************************************
	 */
	start = std::clock();
	smallResult2 = PrefixAverage2(smallVector);
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

	cout << "\tSmall PrefixAverage2\n";
	cout << "Input: 0 1 2 3 ...\n";
	cout << "Output: ";
	for (int i = 0; i <= 3; i++) {
		cout << smallResult2.at(i) << " ";
	}
	cout << "...\nTime(s): " << duration << endl << endl;

	/*
	 * *********************MEDIUM**************************************
	 */
	start = std::clock();
	medResult2 = PrefixAverage2(medVector);
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

	cout << "\tMedium PrefixAverage2\n";
	cout << "Input: 0 1 2 3 ...\n";
	cout << "Output: ";
	for (int i = 0; i <= 3; i++) {
		cout << medResult2.at(i) << " ";
	}
	cout << "...\nTime(s): " << duration << endl << endl;

	/*
	 * *********************LARGE**************************************
	 */
	start = std::clock();
	largeResult2 = PrefixAverage2(largeVector);
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

	cout << "\tLarge PrefixAverage2\n";
	cout << "Input: 0 1 2 3 ...\n";
	cout << "Output: ";
	for (int i = 0; i <= 3; i++) {
		cout << largeResult2.at(i) << " ";
	}
	cout << "...\nTime(s): " << duration << endl << endl;

	return 0;
}

vector<int> PrefixAverage1(vector<int> temp) {
	vector<int> A;
	int a;
	int n = temp.size() - 1;
	for (int i = 0; i <= n; i++) {
		a = 0;
		for (int j = 0; j <= i; j++) {
			a = a + temp.at(j);
		}
		A.push_back(a / (i + 1));
	}
	return A;
}

vector<int> PrefixAverage2(vector<int> temp) {
	vector<int> A;
	int s = 0;
	int n = temp.size() - 1;
	for (int i = 0; i <= n; i++) {
		s = s + temp.at(i);
		A.push_back(s / (i + 1));
	}
	return A;
}
