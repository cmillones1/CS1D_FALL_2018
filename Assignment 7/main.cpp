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

#include "MapAdt.h"

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "      Christopher Millones\n";
	cout << setw(10) << "ASSIGNMENT #:  7\n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: " << "      Mondays & Wednesday: 5:00 - 7:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      10/17/18\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout << "Part 1 Create a map using"
			" the double hashing algorithm where:\n"
			"h(k) = k mod 29\n"
			"h’(k) = 11 - k mod 11\n"
			"N = 29 (size of the array)\n\n"
			"Part 2 Create a map using the quadratic hashing algorithm where:\n"
			"h(k) = k mod 29\n\n";
}


int main()
{
	PRINTAUTHOR();
	INSTRUCTIONS();

	Map<location> mapAdt;
	Map<location> mapAdtTwo;
	string instruction;



	fstream inFile;
	inFile.open("data.txt");
	cout << "\t-INSTRUCTIONS FOR PART 1 and PART 2-\n";
	while(!inFile.eof())
	{
		getline(inFile,instruction);
		cout << instruction << endl;
	}





	location inputQuadHashingArray[] = { {18,"Laguna Niguel"}, {41, "Mission Viejo"},
							{22, "San Clemente"},   {44, "Irvine"},
							{58, "Lake Forest"},    {32, "San Diego"},
							{49, "Anaheim"},        {31, "Los Angeles"},
							{17, "Orange"},         {72, "Palms Springs"},
							{41, "Riverside"},      {19, "Brea"},
							{60, "Santa Ana"},      {35, "Tustin"},
							{103, "Oceanside"},     {11, "La Jolla"},
							{18, "Del Mar"},        {22, "Aliso Veijo"},
							{49, "Laguna Beach"},   {42, "Vista"},
							{49, "San Diego"},      {99, "San Juan"},
							{29, "Dana Point"},     {88, "El Segundo"},
							{41, "San Clemente"},   {62, "Laguna Hills"} };

	int locations = sizeof(inputQuadHashingArray)/sizeof(inputQuadHashingArray[0]);
	mapAdt.putQuadHashing( inputQuadHashingArray[0] );
	mapAdt.putQuadHashing( inputQuadHashingArray[1] );
	mapAdt.putQuadHashing( inputQuadHashingArray[2] );
	mapAdt.putQuadHashing( inputQuadHashingArray[3] );
	mapAdt.erase(41);



	mapAdt.putQuadHashing( inputQuadHashingArray[4] );
	mapAdt.putQuadHashing( inputQuadHashingArray[5] );
	mapAdt.putQuadHashing( inputQuadHashingArray[6] );
	mapAdt.erase(58);



	mapAdt.putQuadHashing( inputQuadHashingArray[7] );
	mapAdt.putQuadHashing( inputQuadHashingArray[8] );
	mapAdt.putQuadHashing( inputQuadHashingArray[9] );
	mapAdt.putQuadHashing( inputQuadHashingArray[10] );
	mapAdt.erase(72);




	mapAdt.putQuadHashing( inputQuadHashingArray[11] );
	mapAdt.putQuadHashing( inputQuadHashingArray[12] );
	mapAdt.putQuadHashing( inputQuadHashingArray[13] );
	mapAdt.putQuadHashing( inputQuadHashingArray[14] );
	mapAdt.putQuadHashing( inputQuadHashingArray[15] );
	mapAdt.putQuadHashing( inputQuadHashingArray[16] );
	mapAdt.putQuadHashing( inputQuadHashingArray[17] );
	mapAdt.putQuadHashing( inputQuadHashingArray[18] );
	mapAdt.erase(41);



	mapAdt.putQuadHashing( inputQuadHashingArray[19] );
	mapAdt.putQuadHashing( inputQuadHashingArray[20] );
	mapAdt.putQuadHashing( inputQuadHashingArray[21] );
	mapAdt.putQuadHashing( inputQuadHashingArray[22] );
	mapAdt.putQuadHashing( inputQuadHashingArray[23] );
	mapAdt.putQuadHashing( inputQuadHashingArray[24] );
	mapAdt.putQuadHashing( inputQuadHashingArray[25] );



	cout << "\n\n\tFinal Map for part 1:\n";
	mapAdt.printHashBucket();




//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[0] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[1] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[2] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[3] );
//	mapAdtTwo.erase(41);
//
//
//
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[4] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[5] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[6] );
//	mapAdtTwo.erase(58);
//
//
//
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[7] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[8] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[9] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[10] );
//	mapAdtTwo.erase(72);
//
//
//
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[11] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[12] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[13] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[14] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[15] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[16] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[17] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[18] );
//	mapAdtTwo.erase(41);
//
//
//
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[19] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[20] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[21] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[22] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[23] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[24] );
//	mapAdtTwo.putQuadHashing( inputQuadHashingArray[25] );
//
//
//
//	cout << "Final Hash Bucket:\n";
//	mapAdtTwo.printHashBucket();




	return 0;
}
